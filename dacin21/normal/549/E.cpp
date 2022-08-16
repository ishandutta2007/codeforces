// Linear programming with arbitrary precision
// (using a modified version of the Num library)
// by dacin21


#ifndef NUM_HPP
#define NUM_HPP
// Based on num biginteger library
// https://github.com/983/Num

// Some slight modification have been done,
// mainly adding move semantics, better RVO
// and i/o operators.

#include <iostream>

#include <math.h>
#include <stdint.h>
#include <limits.h>

#include <vector>
#include <algorithm>
#include <ostream>

class Num {
public:
 typedef uint64_t word;

 std::vector<word> words;
 bool neg;

 static word word_mask(){
  return (word)-1;
 }

 static size_t word_bits(){
  return sizeof(word)*CHAR_BIT;
 }

 static word word_half_mask(){
  return word_mask() >> word_bits()/2;
 }

 static word char_to_word(char c){
  switch (c){
   case '0': return 0;
   case '1': return 1;
   case '2': return 2;
   case '3': return 3;
   case '4': return 4;
   case '5': return 5;
   case '6': return 6;
   case '7': return 7;
   case '8': return 8;
   case '9': return 9;
   case 'a': case 'A': return 10;
   case 'b': case 'B': return 11;
   case 'c': case 'C': return 12;
   case 'd': case 'D': return 13;
   case 'e': case 'E': return 14;
   case 'f': case 'F': return 15;
   case 'g': case 'G': return 16;
   case 'h': case 'H': return 17;
   case 'i': case 'I': return 18;
   case 'j': case 'J': return 19;
   case 'k': case 'K': return 20;
   case 'l': case 'L': return 21;
   case 'm': case 'M': return 22;
   case 'n': case 'N': return 23;
   case 'o': case 'O': return 24;
   case 'p': case 'P': return 25;
   case 'q': case 'Q': return 26;
   case 'r': case 'R': return 27;
   case 's': case 'S': return 28;
   case 't': case 'T': return 29;
   case 'u': case 'U': return 30;
   case 'v': case 'V': return 31;
   case 'w': case 'W': return 32;
   case 'x': case 'X': return 33;
   case 'y': case 'Y': return 34;
   case 'z': case 'Z': return 35;
   default: return word_mask();
  }
 }

 static word word_gcd(word a, word b){
  while (1){
   if (a == 0) return b;
   b %= a;
   if (b == 0) return a;
   a %= b;
  }
 }

 Num(): neg(false){}

 Num(size_t n, word w, bool neg_ = false): words(n, w), neg(neg_){}

 Num(const word *a, const word *b, bool neg_ = false) : words(a, b), neg(neg_){}

 Num(const Num &a){
  words = a.words;
  neg = a.neg;
 }

 Num& operator = (const Num &a){
  words = a.words;
  neg = a.neg;
  return *this;
 }
 Num(Num &&a) = default;
 Num& operator=(Num&&a) = default;

 Num(int i): neg(i < 0){
  for (unsigned u = std::abs(i); u;){
   push_back(u);
   // carefully shift 'u' bit-by-bit because u >>= 32 might be undefined
   for (size_t j = 0; j < word_bits(); j++) u >>= 1;
  }
 }

 Num(const char *c, word base = 10, char **endptr = NULL): neg(false){
  // read sign
  if (*c == '-'){
   c++;
   neg = true;
  }
  // read digits
  for (;*c; c++){
   mul_word(base);
   word b = char_to_word(*c);
   if (b >= base) break;
   add_word(b);
  }
  if (endptr) *endptr = (char*)c;
 }

 void resize(size_t n){
  words.resize(n);
 }

 void pop_back(){
  words.pop_back();
 }

 void push_back(word b){
  words.push_back(b);
 }

 word& back(){
  return words.back();
 }

 const word& back() const {
  return words.back();
 }

 size_t size() const {
  return words.size();
 }

 word& operator [] (size_t i){
  return words[i];
 }

 const word& operator [] (size_t i) const {
  return words[i];
 }

 Num& set_neg(bool neg_){
  this->neg = neg_;
  return *this;
 }

 Num& truncate(){
  while (size() > 0 && words.back() == 0) pop_back();
  return *this;
 }

 size_t bitlength() const {
  if (size() == 0) return 0;
  size_t last = size() - 1;
  size_t result = word_bitlength((*this)[last]) + last*word_bits();
  return result;
 }

 size_t count_trailing_zeros() const {
  for (size_t i = 0; i < size(); i++){
   word w = (*this)[i];
   if (w) return word_count_trailing_zeros(w) + i*word_bits();
  }
  return 0;
 }

 static int cmp_abs(const Num &a, const Num &b){
  size_t na = a.size(), nb = b.size();
  if (na != nb){
   return na < nb ? -1 : +1;
  }
  for (size_t i = na; i --> 0;){
   word wa = a[i], wb = b[i];
   if (wa != wb){
    return wa < wb ? -1 : +1;
   }
  }
  return 0;
 }

 static int cmp(const Num &a, const Num &b){
  if (a.size() == 0 && b.size() == 0) return 0;
  if (!a.neg && !b.neg) return +cmp_abs(a, b);
  if ( a.neg &&  b.neg) return -cmp_abs(a, b);
  return a.neg && !b.neg ? -1 : +1;
 }

 static size_t word_bitlength(word a){
  for (int i = word_bits() - 1; i >= 0; i--) if ((a >> i) & 1) return i+1;
  return 0;
 }

 static size_t word_count_trailing_zeros(word a){
  for (int i = 0; i < (int)word_bits(); i++) if ((a >> i) & 1) return i;
  return word_bits();
 }

 static word add_carry(word *a, word b){
  return (*a += b) < b;
 }

 static word sub_carry(word *a, word b){
  word tmp = *a;
  return (*a = tmp - b) > tmp;
 }

 static word word_mul_hi(word a, word b){
  size_t n = word_bits()/2;
  word a_hi = a >> n;
  word a_lo = a & word_half_mask();
  word b_hi = b >> n;
  word b_lo = b & word_half_mask();
  word tmp = ((a_lo*b_lo) >> n) + a_hi*b_lo;
  tmp = (tmp >> n) + ((a_lo*b_hi + (tmp & word_half_mask())) >> n);
  return tmp + a_hi*b_hi;
 }

 static Num& add_unsigned_overwrite(Num &a, const Num &b){
  size_t i, na = a.size(), nb = b.size(), n = std::max(na, nb);
  a.resize(n);
  word carry = 0;
  for (i = 0; i < nb; i++){
   carry  = add_carry(&a[i], carry);
   carry += add_carry(&a[i], b[i]);
  }
  for (; i < n && carry; i++) carry = add_carry(&a[i], carry);
  if (carry) a.push_back(carry);
  return a.truncate();
 }

 static Num& sub_unsigned_overwrite(Num &a, const Num &b){
  //assert(cmp_abs(a, b) >= 0);
  size_t i, na = a.size(), nb = b.size();
  word carry = 0;
  for (i = 0; i < nb; i++){
   carry  = sub_carry(&a[i], carry);
   carry += sub_carry(&a[i], b[i]);
  }
  for (; i < na && carry; i++) carry = sub_carry(&a[i], carry);
  //assert(!carry);
  return a.truncate();
 }

 static Num mul_long(const Num &a, const Num &b){
  size_t na = a.size(), nb = b.size(), nc = na + nb + 1;
  Num c(nc, 0, a.neg ^ b.neg), carries(nc, 0);
  for (size_t ia = 0; ia < na; ia++){
   for (size_t ib = 0; ib < nb; ib++){
    size_t i = ia + ib, j = i + 1;
    // WARNING: Might overflow if word size is chosen too small
    carries[i + 1] += add_carry(&c[i], a[ia] * b[ib]);
    carries[j + 1] += add_carry(&c[j], word_mul_hi(a[ia], b[ib]));
   }
  }
  // enable RVO
  add_unsigned_overwrite(c, carries);
  c.truncate();
  return c;
  //return add_unsigned_overwrite(c, carries).truncate();
 }
 static void addmul_long(Num &out, const Num &a, const Num &b){
  size_t na = a.size(), nb = b.size(), nc = na + nb + 1;
  //Num c(nc, 0, a.neg ^ b.neg), carries(nc, 0);
  static Num c, carries;
  c.words.assign(nc, 0); c.neg = a.neg ^ b.neg;
  carries.words.assign(nc, 0); carries.neg = 0;
  for (size_t ia = 0; ia < na; ia++){
   for (size_t ib = 0; ib < nb; ib++){
    size_t i = ia + ib, j = i + 1;
    // WARNING: Might overflow if word size is chosen too small
    carries[i + 1] += add_carry(&c[i], a[ia] * b[ib]);
    carries[j + 1] += add_carry(&c[j], word_mul_hi(a[ia], b[ib]));
   }
  }
  // enable RVO
  add_unsigned_overwrite(c, carries);
  c.truncate();
  if(c.size() == out.size()){ // add inplace if possible. This always happens when computing l^2-norms.
   add_unsigned_overwrite(out, c);
  } else {
   out+=c;
  }
 }

 static Num mul_karatsuba(const Num &a, const Num &b){
  size_t na = a.size(), nb = b.size(), n = std::max(na, nb), m2 = n/2 + (n & 1);
  Num a_parts[2], b_parts[2];
  split(a, a_parts, 2, m2);
  split(b, b_parts, 2, m2);
  m2 *= word_bits();
  Num z0 = a_parts[0] * b_parts[0];
  Num z1 = (a_parts[0] + a_parts[1]) * (b_parts[0] + b_parts[1]);
  Num z2 = a_parts[1] * b_parts[1];
  Num result = z2;
  result <<= m2;
  result += z1 - z2 - z0;
  result <<= m2;
  result += z0;
  return result;
 }

 static Num mul(const Num &a, const Num &b){
  size_t karatsuba_threshold = 20;
  if (a.size() > karatsuba_threshold && b.size() > karatsuba_threshold){
   return mul_karatsuba(a, b);
  }
  return mul_long(a, b);
 }

 static Num add_signed(const Num &a, bool a_neg, const Num &b, bool b_neg){
  if (a_neg == b_neg) return std::move(add_unsigned(a, b).set_neg(a_neg));
  if (cmp_abs(a, b) >= 0) return std::move(sub_unsigned(a, b).set_neg(a_neg));
  return std::move(sub_unsigned(b, a).set_neg(b_neg));
 }

 Num& operator >>= (size_t n_bits){
  if (n_bits == 0) return *this;
  size_t n_words = n_bits / word_bits();
  if (n_words >= size()){
   resize(0);
   return *this;
  }
  n_bits %= word_bits();
  if (n_bits == 0){
   for (size_t i = 0; i < size() - n_words; i++){
    (*this)[i] = (*this)[i + n_words];
   }
  }else{
   word hi, lo = (*this)[n_words];
   for (size_t i = 0; i < size() - n_words - 1; i++){
    hi = (*this)[i + n_words + 1];
    (*this)[i] = (hi << (word_bits() - n_bits)) | (lo >> n_bits);
    lo = hi;
   }
   (*this)[size() - n_words - 1] = lo >> n_bits;
  }
  resize(size() - n_words);
  return truncate();
 }

 Num& operator <<= (size_t n_bits){
  if (n_bits == 0) return *this;
  size_t n_words = n_bits / word_bits();
  n_bits %= word_bits();
  size_t old_size = size();
  size_t n = old_size + n_words + (n_bits != 0);
  resize(n);
  if (n_bits == 0){
   for (size_t i = n; i --> n_words;){
    (*this)[i] = (*this)[i - n_words];
   }
  }else{
   word lo, hi = 0;
   for (size_t i = n - 1; i > n_words; i--){
    lo = (*this)[i - n_words - 1];
    (*this)[i] = (hi << n_bits) | (lo >> (word_bits() - n_bits));
    hi = lo;
   }
   (*this)[n_words] = hi << n_bits;
  }
  for (size_t i = 0; i < n_words; i++) (*this)[i] = 0;
  return truncate();
 }

 static void div_mod(const Num &numerator, Num denominator, Num &quotient, Num &remainder){
  quotient = 0;
  remainder = numerator;
  if (cmp_abs(remainder, denominator) >= 0){
   int n = numerator.bitlength() - denominator.bitlength();
   denominator <<= n;
   for (; n >= 0; n--){
    if (cmp_abs(remainder, denominator) >= 0){
     sub_unsigned_overwrite(remainder, denominator);
     quotient.set_bit(n);
    }
    denominator >>= 1;
   }
  }
  quotient.set_neg(numerator.neg ^ denominator.neg);
  remainder.set_neg(numerator.neg);
 }

 static void div_mod_half_word(const Num &numerator, word denominator, Num &quotient, word &remainder){
  remainder = 0;
  Num dst(numerator.size(), 0);

  for (size_t i = numerator.size(); i --> 0;){
   word dst_word = 0;
   word src_word = numerator[i];
   word parts[2];
   parts[0] = src_word >> word_bits()/2;
   parts[1] = src_word & word_half_mask();

   for (size_t j = 0; j < 2; j++){
    remainder <<= word_bits()/2;
    remainder |= parts[j];

    word div_word = remainder / denominator;
    word mod_word = remainder % denominator;
    remainder = mod_word;

    dst_word <<= word_bits()/2;
    dst_word |= div_word;
   }

   dst[i] = dst_word;
  }

  quotient = dst.truncate().set_neg(numerator.neg);
 }

 static void split(const Num &a, Num *parts, size_t n_parts, size_t n){
  size_t i = 0;
  for (size_t k = 0; k < n_parts; k++){
   Num &part = parts[k];
   part.resize(n);
   for (size_t j = 0; j < n && i < a.size(); j++) part[j] = a[i++];
   part = part.truncate();
  }
 }

 static Num div(const Num &numerator, const Num& denominator){
  Num quotient, remainder;
  div_mod(numerator, denominator, quotient, remainder);
  return quotient;
 }

 static Num mod(const Num &numerator, const Num& denominator){
  Num quotient, remainder;
  div_mod(numerator, denominator, quotient, remainder);
  return remainder;
 }

 static Num add_unsigned(const Num &a, const Num &b){
  Num result(a);
  // enable RVO
  add_unsigned_overwrite(result, b);
  return result;
  //return add_unsigned_overwrite(result, b);
 }

 static Num sub_unsigned(const Num &a, const Num &b){
  Num result(a);
  // enable RVO
  sub_unsigned_overwrite(result, b);
  return result;
  // return sub_unsigned_overwrite(result, b);
 }

 static Num add(const Num &a, const Num &b){
  Num result = add_signed(a, a.neg, b, b.neg);
  return result;
 }

 static Num sub(const Num &a, const Num &b){
  Num result = add_signed(a, a.neg, b, !b.neg);
  return result;
 }

 static Num gcd(const Num &a0, const Num &b0){

  if (a0.size() == 1 && b0.size() == 1){
   return Num(1, word_gcd(a0[0], b0[0]));
  }

  Num a(a0), b(b0);
  a.neg = b.neg = false;

  if (a.size() == 0) return b0;
  if (b.size() == 0) return a0;

  size_t n = a.count_trailing_zeros();
  size_t m = b.count_trailing_zeros();
  if (n > m) {
   std::swap(n, m);
   a.words.swap(b.words);
  }

  a >>= n;
  b >>= n;

  do {
   b >>= b.count_trailing_zeros();
   if (cmp_abs(a, b) > 0) a.words.swap(b.words);
   sub_unsigned_overwrite(b, a);
  } while (b.size() > 0);

  a <<= n;

  return a;
 }

 static Num abs(Num const&x) {
  Num ret(x);
  ret.set_neg(false);
  return ret;
 }

 typedef void (*random_func)(uint8_t *bytes, size_t n_bytes);

 static Num random_bits(size_t n_bits, random_func func){
  if (n_bits == 0) return 0;
  size_t partial_bits = n_bits % word_bits();
  size_t n_words = n_bits / word_bits() + (partial_bits > 0);
  size_t n_bytes = n_words*sizeof(word);
  Num result(n_words, 0);
  uint8_t *bytes = (uint8_t*)&result[0];
  func(bytes, n_bytes);
  if (partial_bits){
   size_t too_many_bits = word_bits() - partial_bits;
   result.back() >>= too_many_bits;
  }
  return result;
 }

 static Num random_inclusive(const Num &inclusive, random_func func){
  size_t n_bits = inclusive.bitlength();
  while (true){
   Num result = random_bits(n_bits, func);
   if (result <= inclusive) return result;
  }
 }

 static Num random_exclusive(const Num &exclusive, random_func func){
  size_t n_bits = exclusive.bitlength();
  while (true){
   Num result = random_bits(n_bits, func);
   if (result < exclusive) return result;
  }
 }

 static Num random_second_exclusive(const Num &inclusive_min_val, const Num &exclusive_max_val, random_func func){
  return inclusive_min_val + random_exclusive(exclusive_max_val - inclusive_min_val, func);
 }

 static Num random_both_inclusive(const Num &inclusive_min_val, const Num &inclusive_max_val, random_func func){
  return inclusive_min_val + random_inclusive(inclusive_max_val - inclusive_min_val, func);
 }

 Num& set_bit(size_t i){
  size_t i_word = i / word_bits();
  size_t i_bit =  i % word_bits();
  if (size() <= i_word) resize(i_word + 1);
  (*this)[i_word] |= ((word)1) << i_bit;
  return *this;
 }

 word get_bit(size_t i) const {
  size_t i_word = i / word_bits();
  size_t i_bit =  i % word_bits();
  if (i_word >= size()) return 0;
  return ((*this)[i_word] >> i_bit) & 1;
 }

 void clr_bit(size_t i){
  size_t i_word = i / word_bits();
  size_t i_bit =  i % word_bits();
  if (i_word >= size()) return;
  word mask = 1;
  mask <<= i_bit;
  (*this)[i_word] &= ~mask;
 }

 Num& mul_word(word b){
  word carry = 0;
  for (size_t i = 0; i < size(); i++){
   word a = (*this)[i];
   word tmp = a * b;
   carry = add_carry(&tmp, carry);
   carry += word_mul_hi(a, b);
   (*this)[i] = tmp;
  }
  if (carry) push_back(carry);
  return truncate();
 }

 Num& add_word(word carry, size_t i0 = 0){
  if (i0 >= size()) resize(i0 + 1);
  for (size_t i = i0; i < size() && carry; i++){
   carry = add_carry(&(*this)[i], carry);
  }
  if (carry) push_back(carry);
  return truncate();
 }

 void print(
  std::vector<char> &text,
  word base = 10,
  const char *alphabet = "0123456789abcdefghijklmnopqrstuvwxyz"
 ) const {
  if (size() == 0){
   text.push_back('0');
  }else{
   Num tmp(*this);
   while (tmp.size() > 0){
    word remainder;
    div_mod_half_word(tmp, base, tmp, remainder);
    text.push_back(alphabet[remainder]);
   }
   if (neg) text.push_back('-');
   std::reverse(text.begin(), text.end());
  }
  text.push_back('\0');
 }

 double to_double() const {
  if (size() == 0) return 0.0;
  double d = 0.0, base = ::pow(2.0, word_bits());
  for (size_t i = size(); i --> 0;) d = d * base + (*this)[i];
  return neg ? -d : d;
 }

 bool can_convert_to_int(int *result) const {
  if (*this < Num(INT_MIN) || *this > Num(INT_MAX)) return false;

  unsigned temp = 0;

  for (size_t i = words.size(); i --> 0;){
   temp <<= word_bits();
   temp += (*this)[i];
  }

  *result = neg ? -temp : temp;

  return true;
 }

 Num pow(size_t exponent) const {
  Num result(1), p(*this);
  for (; exponent; exponent >>= 1){
   if (exponent & 1){
    result = result * p;
    exponent--;
   }
   p = p*p;
  }
  return result;
 }

 Num mod_pow(Num exponent, const Num &modulus) const {
  Num result(1), base = (*this) % modulus;
  for (; exponent.size() > 0; exponent >>= 1){
   if (exponent.get_bit(0)){
    result = (result * base) % modulus;
   }
   base = (base * base) % modulus;
  }
  return result;
 }

 Num sqrt() const {
  Num n = *this;
  int bit = bitlength();
  if (bit & 1) bit ^= 1;
  Num result = 0;
  for (; bit >= 0; bit -= 2){
   Num tmp = result;
   tmp.set_bit(bit);
   if (n >= tmp){
    n -= tmp;
    result.set_bit(bit + 1);
   }
   result >>= 1;
  }
  return result;
 }

 int sign() const { return cmp(*this, Num(0)); }

 Num& operator ++(){
  add_word(1);
  return *this;
 }

 Num& operator += (const Num &b){ return *this = add(*this, b); }
 Num& operator -= (const Num &b){ return *this = sub(*this, b); }
 Num& operator *= (const Num &b){ return *this = mul(*this, b); }
 Num& operator /= (const Num &b){ return *this = div(*this, b); }
 Num& operator %= (const Num &b){ return *this = mod(*this, b); }

 bool operator == (const Num &b) const { return cmp(*this, b) == 0; }
 bool operator != (const Num &b) const { return cmp(*this, b) != 0; }
 bool operator <= (const Num &b) const { return cmp(*this, b) <= 0; }
 bool operator >= (const Num &b) const { return cmp(*this, b) >= 0; }
 bool operator <  (const Num &b) const { return cmp(*this, b) <  0; }
 bool operator >  (const Num &b) const { return cmp(*this, b) >  0; }

 Num operator + (const Num &b) const { return add(*this, b); }
 Num operator - (const Num &b) const { return sub(*this, b); }
 Num operator * (const Num &b) const { return mul(*this, b); }
 Num operator / (const Num &b) const { return div(*this, b); }
 Num operator % (const Num &b) const { return mod(*this, b); }
 // Num operator - (            ) const { return Num(*this).set_neg(!neg); }
 Num operator - (            ) const { Num ret(*this); ret.set_neg(!neg); return ret; } // RVO

 Num operator >> (size_t n_bits) const { return Num(*this) >>= n_bits; }
 Num operator << (size_t n_bits) const { return Num(*this) <<= n_bits; }
};
std::ostream& operator<<(std::ostream&o, Num const&n){
 std::vector<char> tmp;
 n.print(tmp);
 o << tmp.data();
 return o;
}
#endif // NUM_HPP
#ifndef FRACTION_HPP
#define FRACTION_HPP


namespace dacin{ namespace lp{

 class Fraction{
 public:
  Fraction() : a(0), b(1) {}
  explicit Fraction(Num x) : a(std::move(x)), b(1) {}
  Fraction(Num numerator, Num denominator) : a(std::move(numerator)), b(std::move(denominator)) { fix_sign(); }

  static Fraction inf(){return Fraction(1, 0);}

  Fraction& operator+=(Fraction const&o){
   a *= o.b;
   a += b*o.a;
   b *= o.b;
   return *this;
  }
  Fraction operator+(Fraction const&o) const {
   Fraction ret(*this);
   ret+=o;
   return ret;
  }
  Fraction& operator-=(Fraction const&o){
   a *= o.b;
   a += b*o.a;
   b *= o.b;
   return *this;
  }
  Fraction operator-(Fraction const&o) const {
   Fraction ret(*this);
   ret-=o;
   return ret;
  }

  Fraction& operator*=(Fraction const&o){
   a*=o.a;
   b*=o.b;
   return *this;
  }
  Fraction operator*(Fraction const&o) const {
   Fraction ret(*this);
   ret*=o;
   return ret;
  }
  Fraction& operator/=(Fraction const&o){
   a*=o.b;
   b*=o.a;
   return *this;
  }
  Fraction operator/(Fraction const&o) const {
   Fraction ret(*this);
   ret/=o;
   return ret;
  }
  Fraction operator-() const {
   return Fraction(-a, b);
  }

  int cmp(Fraction const&o) const {
   if(a.neg != o.a.neg){ // fix -inf < inf
    return a.neg ? -1 : 1;
   }
   return Num::cmp(a * o.b, b * o.a);
  }
  #define DECLARE_CMP_OP(op)\
  bool operator op (Fraction const&o) const{\
   return cmp(o) op 0;\
  }
  DECLARE_CMP_OP(<)
  DECLARE_CMP_OP(>)
  DECLARE_CMP_OP(<=)
  DECLARE_CMP_OP(>=)
  DECLARE_CMP_OP(==)
  DECLARE_CMP_OP(!=)
  #undef DECLARE_CMP_OP


  friend std::ostream& operator<<(std::ostream&o, Fraction const&f){
   return o << f.a << "/" << f.b;
  }

 private:
  void fix_sign(){
   if(a == Num(0)){
    if(b != Num(0)){
     b = Num(1);
    }
   } else {
    if(b < Num(0)){
     a.set_neg(-a.neg);
     b.set_neg(false);
    }
   }
  }
  Num a, b;
 };

} }
#endif // FRACTION_HPP
#ifndef LP_INSTANCE_HPP
#define LP_INSTANCE_HPP

#include <cassert>
#include <istream>
#include <ostream>


namespace dacin{ namespace lp{

 class Lp_Instance{
 public:
  Lp_Instance() {}
  Lp_Instance(std::vector<std::vector<Num> > A_, std::vector<Num> c_) : A(std::move(A_)), c(std::move(c_)) { for(auto const&e:A) assert(e.size() == c.size()+1); }
  Lp_Instance(std::vector<std::vector<Num> > A_, std::vector<Num> b, std::vector<Num> c_) : A(std::move(A_)), c(std::move(c_)) {
   assert(A.size() == b.size());
   for(size_t i=0;i<A.size();++i){
    assert(A[i].size() == c.size());
    A[i].push_back(-b[i]);
   }
  }
  friend std::istream& operator>>(std::istream&in, Lp_Instance &lp){
   int n, d;
   in >> n >> d;
   std::vector<std::vector<Num> > A(n, std::vector<Num>(d+1));
   std::vector<Num> c(d);
   std::string s;
   auto read_num = [&in, &s](Num&f){
    in >> s;
    f = std::move(Num(s.c_str()));
   };
   for(auto &e:A) for(auto &f:e) read_num(f);
   for(auto &e:c) read_num(e);
   lp.set_A(std::move(A));
   lp.set_c(std::move(c));
   return in;
  }
  friend std::ostream& operator<<(std::ostream&o, Lp_Instance const&lp){
   o << lp.A.size() << " " << lp.c.size() << "\n";
   auto write_num = [&o](Num const&f){
    int g; assert(f.can_convert_to_int(&g));
    o << g;
   };
   for(auto &e:lp.A){
    for(auto &f:e) {
     write_num(f);
     o << " ";
    }
    o << "\n";
   }
   for(auto &e:lp.c){
    write_num(e);
    o << " ";
   }
   o << "\n";
   return o;
  }

  std::vector<std::vector<Num> > const& get_A() const { return A; }
  std::vector<Num> const& get_c() const { return c; }
  void set_A(std::vector<std::vector<Num> > A_) { A = std::move(A_); }
  void set_c(std::vector<Num> c_) { c = std::move(c_); }
  int n() const { return A.size(); }
  int d() const { return c.size(); }
 private:
  /*
   * maximize    c * x
   * subject to  A * (x|1) <= 0
   */
  std::vector<std::vector<Num> > A;
  std::vector<Num> c;
 };

} }
#endif // LP_INSTANCE_HPP
#ifndef UTIL_HPP
#define UTIL_HPP

#include <bits/stdc++.h>

namespace dacin{ namespace lp{
 using std::vector;
 using std::move;

 #ifdef LOCAL_RUN
 constexpr int seed = 918273741;
 std::mt19937 rng(918273741);
 #else
 std::mt19937 rng(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());
 #endif // LOCAL_run
 void reset_seed(){
  #ifdef LOCAL_RUN
  rng = decltype(rng)(seed);
  #endif
 }

 Num scal_affine(vector<Num> const&a, vector<Num> const&b){
  size_t n = std::min(a.size(), b.size());
  assert(a.size() <= n+1 && b.size() <= n+1);
  Num ret(0);
  for(size_t i=0; i<n; ++i){
   ret += a[i]*b[i];
  }
  return ret;
 }
 Num scal(vector<Num> const&a, vector<Num> const&b){
  assert(a.size() == b.size());
  return scal_affine(a, b);
 }
 void reduce_by_gcd(vector<Num> &v){
  Num g(0);
  for(auto &e:v){
   g = Num::gcd(e%g, g);
  }
  g.set_neg(false);
  for(auto &e:v){
   e /= g;
  }
 }
 vector<Num> reduced(vector<Num> v){
  reduce_by_gcd(v);
  return v;
 }

} }
#endif // UTIL_HPP
#ifndef LP_RESULT_HPP
#define LP_RESULT_HPP


namespace dacin{ namespace lp{

 enum class Lp_Status{
  INFEASIBLE, OPTIMAL, UNBOUNDED, ERROR
 };

 class Lp_Result{
 public:
  Lp_Result() : status(Lp_Status::ERROR), x(), ray(), objective(0) {}
  Lp_Result(Lp_Status status_, vector<Num> x_, vector<Num> ray_, Fraction objective_) : status(status_), x(std::move(x_)), ray(std::move(ray_)), objective(std::move(objective_)) {}

  static Lp_Result infeasible_result() {
   return Lp_Result(Lp_Status::INFEASIBLE, {}, {}, -Fraction::inf());
  }

  bool is_feasible() const {
   assert(status != Lp_Status::ERROR);
   return status != Lp_Status::INFEASIBLE;
  }
  bool is_bounded() const {
   assert(status != Lp_Status::ERROR);
   return status != Lp_Status::UNBOUNDED;
  }
  vector<Num> const& get_x() const { return x; }
  vector<Num> const& get_ray() const { return ray; }
  void set_x(vector<Num> const& x_){ x = x_; }
  void set_ray(vector<Num> const& ray_){ ray = ray_; }
  Fraction const& get_objective() const { return objective; }

  void reset_ray() {
   assert(is_feasible());
   if(!is_bounded()) status = Lp_Status::OPTIMAL;
   std::fill(ray.begin(), ray.end(), Num(0));
  }
  void recalc_objective(vector<Num> const&c){
   switch(status){
    case Lp_Status::OPTIMAL:
     objective = Fraction(scal_affine(x, c), x.back());
     break;
    case Lp_Status::UNBOUNDED:
     objective = Fraction::inf();
     break;
    case Lp_Status::INFEASIBLE:
     objective = -Fraction::inf();
     break;
    case Lp_Status::ERROR:
     assert(0);
   }
  }
  void reduce_all(){ reduce_by_gcd(x); reduce_by_gcd(ray); }
  bool violates(vector<Num> const&row) const {
   if(!is_bounded()){
    const int sign = Num::cmp(scal(row, ray), Num(0));
    if(sign != 0) return sign == 1 ? true : false;
   }
   return scal(row, x) > Num(0);
  }

 private:
  Lp_Status status;
  vector<Num> x, ray;
  Fraction objective;
 };

} }
#endif // LP_RESULT_HPP
#ifndef SEIDEL_HPP
#define SEIDEL_HPP


namespace dacin{ namespace lp{
 namespace detail{

  std::pair<std::vector<Num>, int> make_projection(std::vector<Num> constraint){
   const int k = std::find_if(constraint.begin(), constraint.end(), [](Num const&x){ return x.sign() != 0; }) - constraint.begin();
   assert(k+1 < (int)constraint.size());
   if(constraint[k].sign() == -1){
    for(auto &e:constraint){
     e = -e;
    }
   }
   return std::make_pair(std::move(constraint), k);
  }
  std::vector<Num> project_down(std::vector<Num> const&vec, std::vector<Num> const&plane, int const i){
   const size_t n = vec.size();
   assert(n <= plane.size() && plane.size() <= n+1);
   assert(plane[i].sign() > 0);
   std::vector<Num> ret(n-1);
   for(int j=0;j<i;++j) ret[j] = vec[j]*plane[i] - vec[i]*plane[j];
   for(int j=i+1;j<(int)n;++j) ret[j-1] = vec[j]*plane[i] - vec[i]*plane[j];
   return ret;
  }
  std::vector<Num> project_up(std::vector<Num> const&vec, std::vector<Num> const&plane, int const i){
   const size_t n = vec.size();
   assert(plane.size() == n+1);
   assert(plane[i].sign() > 0);
   std::vector<Num> ret(n+1);
   for(int j=0;j<i;++j){
    ret[j] = vec[j] * plane[i];
    ret[i] -= vec[j] * plane[j];
   }
   for(int j=i;j<(int)n;++j){
    ret[j+1] = vec[j] * plane[i];
    ret[i] -= vec[j] * plane[j+1];
   }
   return ret;
  }

  Lp_Result seidel_rec(Lp_Instance lp, const bool move_to_front, const size_t front_size = 0){
   const int n = lp.n(), d = lp.d();
   if(d == 0){
    Lp_Result ret(Lp_Status::OPTIMAL, {Num(1)}, {Num(0)}, Fraction(0));
    for(auto const&e:lp.get_A()){
     if(ret.violates(e)) return Lp_Result::infeasible_result();
    }
    return ret;
   }
   auto get_base_result = [&lp, &n, &d](){
    std::vector<Num> x(d+1), ray(d+1);
    x.back() = Num(1);
    for(int i=0;i<d;++i){
     ray[i] = Num(lp.get_c()[i].sign());
    }
    bool obj_unbounded = scal_affine(lp.get_c(), ray).sign() > 0;
    Lp_Result ret(obj_unbounded ? Lp_Status::UNBOUNDED : Lp_Status::OPTIMAL, move(x), move(ray), Fraction(0));
    return ret;
   };
   if(d == 1){
    // solve in deterministic O(n)
    Lp_Result ret = get_base_result();
    for(auto &e:lp.get_A()){
     if(ret.violates(e)){
      switch(e[0].sign()){
       case -1:
        ret.reset_ray();
        ret.set_x({e[1], -e[0]});
        break;
       case 1:
        ret.reset_ray();
        ret.set_x({-e[1], e[0]});
        break;
       case 0:
        return Lp_Result::infeasible_result();
      }
      ret.recalc_objective(lp.get_c());
     }
    }
    for(auto &e:lp.get_A()){
     if(ret.violates(e)){
      return Lp_Result::infeasible_result();
     }
    }
    return ret;
   } else {
    {
     auto &A = const_cast<std::vector<std::vector<Num>>&>(lp.get_A());
     std::shuffle(A.begin() + std::min(front_size, A.size()), A.end(), rng);
    }
    Lp_Result ret = get_base_result();
    vector<int> moved_indices;
    for(int i=0;i<n;++i){
     auto const&e = lp.get_A()[i];
     if(ret.violates(e)){
      // project down, recurse, project up
      auto projection = make_projection(e);
      auto const plane = projection.first;
      const int k = projection.second;
      std::vector<std::vector<Num> > A_sub;
      for(auto it = moved_indices.rbegin(); it != moved_indices.rend();++it){
       A_sub.push_back(std::move(project_down(lp.get_A()[*it], plane, k)));
      }
      for(int j=0;j<i;++j){
       A_sub.push_back(std::move(project_down(lp.get_A()[j], plane, k)));
      }
      std::vector<Num> c_sub = project_down(lp.get_c(), plane, k);
      Lp_Result sub_result = seidel_rec(std::move(Lp_Instance(std::move(A_sub), std::move(c_sub))), move_to_front, front_size + moved_indices.size());
      if(!sub_result.is_feasible()) return sub_result;
      ret = sub_result;
      ret.set_x(project_up(sub_result.get_x(), plane, k));
      ret.set_ray(project_up(sub_result.get_ray(), plane, k));
      if(move_to_front) moved_indices.push_back(i);
     }
    }
    return ret;
   }
  }
 }
 template<bool move_to_front = false>
 Lp_Result solve_seidel(Lp_Instance lp){
  auto const c = lp.get_c();
  auto res = detail::seidel_rec(std::move(lp), move_to_front);
  res.reduce_all();
  res.recalc_objective(c);
  return res;
 }

} }
#endif // SEIDEL_HPP
#ifndef SIMPLEX_HPP
#define SIMPLEX_HPP


namespace dacin{ namespace lp{
 namespace detail{

  void reduce_tableau(vector<vector<Num> > &T, Num& scale){
   Num g = scale;
   for(auto const&e:T){
    for(auto &f:e){
     g = Num::gcd(g, f);
    }
   }
   if(g != Num(1)){
    scale/=g;
    for(auto &e:T){
     for(auto &f:e){
      f/=g;
     }
    }
   }
  }
  void pivot(vector<vector<Num> > &T, Num& scale, vector<int> &basic, vector<int> &nonbasic, int const enter, int const leave){
   const int X = T.size(), Y = T[0].size();
   const Num Drs_abs = Num::abs(T[leave][enter]);
   const int Drs_sign = T[leave][enter].sign();
   for(int i=0;i<X;++i) if(i != leave){
    for(int j=0;j<Y;++j) if(j != enter){
     T[i][j] = T[i][j] * Drs_abs - T[leave][j] * T[i][enter] * Drs_sign;
    }
   }
   for(int j=0;j<Y;++j) if(j != enter){
    T[leave][j] *= scale * Drs_sign;
   }
   for(int i=0;i<X;++i) if(i != leave){
    T[i][enter] *= scale * -Drs_sign;
   }
   T[leave][enter] = scale * scale * Drs_sign;
   scale*= Drs_abs;
   std::swap(basic[leave], nonbasic[enter]);
   reduce_tableau(T, scale);
  }
  int run_phase(vector<vector<Num> > &T, Num&scale, vector<int> &basic, vector<int> &nonbasic, const int phase){
   const int n = T.size()-2, d = T[0].size()-2;
   const int x = phase==1 ? n+1 : n;
   for(;;){
    int enter = -1;
    // primal steepest edge with lexicographical tie breaking
    Fraction slope = Fraction::inf();
    for(int j=0;j<=d;++j){
     if(phase==2 && nonbasic[j] == -1) continue;
     Num norm_sq;
     for(int i=0;i<=n;++i){
      //norm_sq += T[i][j]*T[i][j];
      Num::addmul_long(norm_sq, T[i][j], T[i][j]);
     }
     Fraction slope_j (T[x][j] * Num::abs(T[x][j]), norm_sq);
     if(std::make_pair(slope_j, nonbasic[j]) < std::make_pair(slope, enter==-1 ? -1 : nonbasic[enter])){
      enter = j;
      slope = move(slope_j);
     }
    }
    if(T[x][enter].sign() >= 0) return -1;
    int leave = -1;
    Fraction ratio = Fraction::inf();
    for(int i=0;i<n;++i){
     if(T[i][enter].sign() > 0){
      Fraction ratio_i = Fraction(T[i][d+1], T[i][enter]);
      if(std::make_pair(ratio_i, basic[i])  < std::make_pair(ratio, leave==-1 ? -1 : basic[leave])){
       leave = i;
       ratio = move(ratio_i);
      }
     }
    }
    if(leave == -1) return enter;
    pivot(T, scale, basic, nonbasic, enter, leave);
   }
  }
  Lp_Result tableau_simplex(vector<vector<Num> > T){
   const int n = T.size()-2, d = T[0].size()-2;
   vector<int> basic(n); std::iota(basic.begin(), basic.end(), d);
   vector<int> nonbasic(d+1, -1); std::iota(nonbasic.begin(), prev(nonbasic.end()), 0);
   int leave = 0;
   for(int i=1;i<n;++i){
    if(T[i].back() < T[leave].back()) leave = i;
   }
   Num scale(1);
   if(T[leave][d+1].sign() < 0){
    pivot(T, scale, basic, nonbasic, d, leave);
    const int feasible_fail = run_phase(T, scale, basic, nonbasic, 1);
    if(feasible_fail != -1){
     return Lp_Result::infeasible_result();
    }
    for(int i=0;i<n;++i) if(basic[i] == -1){
     int enter = 0;
     for(int j=1;j<=d;++j){
      if(std::make_pair(T[i][j], nonbasic[j]) < std::make_pair(T[i][enter], nonbasic[enter])){
       enter = j;
      }
     }
     pivot(T, scale, basic, nonbasic, enter, i);
    }
   }
   const int bounded_fail = run_phase(T, scale, basic, nonbasic, 2);
   vector<Num> x(d+1, 0);
   x.back() = scale;
   for(int i=0;i<n;++i) if(basic[i] < d){
    x[basic[i]] = T[i].back();
   }
   if(bounded_fail != -1){
    const int bf = bounded_fail;
    // unbounded ray is needed for clarkson to work
    vector<Num> ray(d+1, 0);
    ray.back() = 0;
    for(int i=0;i<n;++i) if(basic[i] < d){
     ray[basic[i]] = -T[i][bf];
    }
    if(nonbasic[bf] < d){
     ray[nonbasic[bf]] = scale;
    }
    return Lp_Result(Lp_Status::UNBOUNDED, move(x), move(ray), Fraction::inf());
   }
   return Lp_Result(Lp_Status::OPTIMAL, move(x), {}, Fraction(T[n].back(), scale));
  }
 }

 vector<Num> transform_back(vector<Num> const&v){
  assert(v.size()%2 == 1);
  const int d0 = v.size()/2;
  vector<Num> ret(d0+1);
  for(int i=0;i<d0;++i){
   ret[i] = v[2*i] - v[2*i+1];
  }
  ret.back() = v.back();
  return ret;
 }

 Lp_Result solve_simplex(Lp_Instance lp){
  const int d0 = lp.d();
  const int d = 2*d0;
  const int n = lp.n();
  vector<vector<Num> > T(n+2, vector<Num>(d+2));
  for(int i=0;i<n;++i){
   for(int j=0;j<d0;++j){
    T[i][2*j] = lp.get_A()[i][j];
    T[i][2*j+1] = -lp.get_A()[i][j];
   }
   T[i][d] = Num(-1);
   T[i][d+1] = -lp.get_A()[i].back();
  }
  for(int j=0;j<d0;++j){
   T[n][2*j] = -lp.get_c()[j];
   T[n][2*j+1] = lp.get_c()[j];
  }
  T[n+1][d] = Num(1);
  Lp_Result ret = detail::tableau_simplex(move(T));
  if(ret.is_feasible()){
   ret.set_x(move(transform_back(ret.get_x())));
  }
  if(!ret.is_bounded()){
   ret.set_ray(move(transform_back(ret.get_ray())));
  }
  ret.reduce_all();
  return ret;
 }

} }
#endif // SIMPLEX_HPP
#ifndef CLARKSON_HPP
#define CLARKSON_HPP


namespace dacin{ namespace lp{

 using Backend = Lp_Result(*)(Lp_Instance);
 namespace detail{
  template<typename T>
  T randint(T l, T r){
   return std::uniform_int_distribution<T>(l, r)(rng);
  }
  Lp_Result clarkson_1(vector<vector<Num> > const&A, vector<Num> const&c, Backend backend){
   const int n = A.size(), d = c.size();
   const int k = 6*d*d;
   vector<int64_t> weight(n, 1);
   if(n <= k) return backend(std::move(Lp_Instance(A, c)));
   auto get_sublp = [&A, &c, &weight, n, d, k](){
    int64_t total_weight = std::accumulate(weight.begin(), weight.end(), int64_t{0});
    vector<int64_t> samples;
    while((int)samples.size() < k){
     int64_t new_sample = randint<int64_t>(0, total_weight-1);
     if(!std::count(samples.begin(), samples.end(), new_sample)){
      samples.push_back(new_sample);
     }
    }
    std::sort(samples.begin(), samples.end());
    int64_t weight_pre = 0;
    vector<vector<Num> > A_sub;
    for(int i=0, j=0; i<n && j<k; ++i){
     weight_pre += weight[i];
     if(samples[j] < weight_pre){
      A_sub.push_back(A[i]);
      ++j;
     }
    }
    return Lp_Instance(std::move(A_sub), c);
   };
   vector<bool> is_violated(n);
   for(size_t iter = 0;;++iter){
    auto res = backend(std::move(get_sublp()));
    if(!res.is_feasible()){
     return res;
    }
    int64_t violated_weight = 0;
    int64_t total_weight = 0;
    for(int i=0;i<n;++i){
     is_violated[i] = res.violates(A[i]);
     total_weight+=weight[i];
     if(is_violated[i]){
      violated_weight+=weight[i];
     }
    }
    if(violated_weight == 0){
     // std::cerr << "Clarkson 1 iter: " << iter << "\n";
     return res;
    }
    if(violated_weight * 3 * d <= total_weight){
     for(int i=0;i<n;++i){
      if(is_violated[i]) weight[i]*=2;
     }
    }
   }
  }
  Lp_Result clarkson_2(vector<vector<Num> > const&A, vector<Num> const&c, Backend backend){
   const int n = A.size(), d = c.size();
   if(n <= 9*d*d){
    return clarkson_1(A, c, backend);
   }
   const int root_n = llround(sqrt(n));
   const int k = d * root_n;
   vector<vector<Num> > A_sub;
   for(;;){
    const int s = A_sub.size();
    for(int i=0;i<k;++i){
     A_sub.push_back(A[randint<int>(0, n-1)]);
    }
    auto res = clarkson_1(A_sub, c, backend);
    A_sub.erase(A_sub.begin()+s, A_sub.end());
    if(!res.is_feasible()){
     return res;
    }
    vector<int> violators;
    for(int i=0;i<n;++i){
     if(res.violates(A[i])) violators.push_back(i);
    }
    if(violators.empty()){
     return res;
    }
    if((int)violators.size() <= 2*root_n){
     for(auto &e:violators){
      A_sub.push_back(A[e]);
     }
    }
   }
  }
 }
 Lp_Result solve_clarkson(Lp_Instance const&lp, Backend backend){
  Lp_Result res = detail::clarkson_2(lp.get_A(), lp.get_c(), backend);
  return res;
 }

 template<bool move_to_front = false>
 Lp_Result solve_clarkson_seidel(Lp_Instance const&lp){
  return solve_clarkson(lp, solve_seidel<move_to_front>);
 }
 Lp_Result solve_clarkson_simplex(Lp_Instance const&lp){
  return solve_clarkson(lp, solve_simplex);
 }

} }
#endif // CLARKSON_HPP
// problem E "Sasha Circle" from 549.
// https://codeforces.com/problemset/problem/549/E

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename S, typename T>
void xmin(S&a, T const&b){if(b<a) a=b;}
template<typename S, typename T>
void xmax(S&a, T const&b){if(b>a) a=b;}

using namespace dacin::lp;

signed main()
{
 #ifdef LOCAL_RUN
 freopen("in.txt", "r", stdin);
 //freopen("out.txt", "w", stdout);
 cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
 int TTT; cin >> TTT;
 while(TTT--){
 #else
 cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
 #endif // LOCAL_RUN

 int n, m;
 cin >> n >> m;

 vector<pair<int, int> > p(n), q(m);
 for(auto &e:p){
  cin >> e.first >> e.second;
 }
 for(auto &e:q){
  cin >> e.first >> e.second;
 }
 bool done = false;
 for(int it=0;it<2;++it){
  vector<vector<Num> > A;
  vector<Num> c{0, 0, 0, 1};
  for(auto &e:p){
   int x, y; tie(x, y) = e;
   A.push_back({x, y, 1, 1, -(x*x+y*y)});
  }
  for(auto &e:q){
   int x, y; tie(x, y) = e;
   A.push_back({-x, -y, -1, 1, +(x*x+y*y)});
  }
  auto res = solve_clarkson_seidel<false>(Lp_Instance(move(A), move(c)));
  if(res.is_feasible()){
   if(res.get_objective() > Fraction()){
    cout << "YES\n";
    done = true;
    break;
   }
  }
  p.swap(q);
  swap(n, m);
 }
 if(!done){
  cout << "NO\n";
 }

 #ifdef LOCAL_RUN
 }
 #endif // LOCAL_RUN
 return 0;
}