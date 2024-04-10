#ifndef CM_DEBUG_H
#define CM_DEBUG_H 1
#include <iostream>
#include <utility>
#include <tuple>
#include <iterator>
#include <string>
namespace cm{class logger{private:std::ostream*out;std::string sep="\x2c\x20";bool _assert_exit=true;std::string c_red="\033[0;31m";std::string c_green="\033[0;32m";std::string c_yellow="\033[0;33m";std::string c_blue="\033[0;34m";std::string c_magenta="\033[0;35m";std::string c_cyan="\033[0;36m";std::string c_red_bold="\033[1;31m";std::string c_green_bold="\033[1;32m";std::string c_yellow_bold="\033[1;33m";std::string c_blue_bold="\033[1;34m";std::string c_magenta_bold="\033[1;35m";std::string c_cyan_bold="\033[1;36m";std::string c_reset="\033[0m";std::string get_color(std::string name){if(name=="red")return c_red;if(name=="green")return c_green;if(name=="yellow")return c_yellow;if(name=="blue")return c_blue;if(name=="magenta")return c_magenta;if(name=="cyan")return c_cyan;if(name=="red bold")return c_red_bold;if(name=="green bold")return c_green_bold;if(name=="yellow bold")return c_yellow_bold;if(name=="blue bold")return c_blue_bold;if(name=="magenta bold")return c_magenta_bold;if(name=="cyan bold")return c_cyan_bold;if(name=="reset")return c_reset;return "";}public:logger(std::ostream&out):out(&out){}logger&set_ostream(std::ostream&out){this->out=&out;return*this;}logger&set_sep(const std::string&sep){this->sep=sep;return*this;}logger&assert_exit(){_assert_exit=true;return*this;}logger&assert_noexit(){_assert_exit=false;return*this;}logger&endl(){*out<<std::endl;return*this;}logger&log(){return*this;}template<class Ta,class Tb,class...Tc>logger&log(const Ta&a,const Tb&b,Tc...c){return log(a).log(sep).log(b,c...);}template<class Ta,typename=decltype(std::cout<<std::declval<Ta>())>logger&log(const Ta&a){*out<<a;return*this;}template<class T,typename=decltype(std::declval<T>().begin()),typename=decltype(std::declval<T>().end()),typename=typename std::enable_if<!std::is_base_of<std::string,typename std::decay<T>::type>::value>::type,typename value_type=typename T::value_type>logger&log(const T&container){log("{");for(auto it=container.begin();it!=container.end();++it){if(it!=container.begin())log(sep);log(*it);}log("}");return*this;}template<class Ta,class Tb>logger&log(const std::pair<Ta,Tb>&x){return log("(").log(x.first,x.second).log(")");}
#if __cplusplus >= 201703L
template<class...T>logger&log(const std::tuple<T...>&x){log("(");std::apply([this](auto...x){this->log(x...);},x);return log(")");}
#else
template<class...T>logger&log(const std::tuple<T...>&){return log("<tuple>");}
#endif
template<class T>logger&hint(const T&x,std::string color="cyan"){color=get_color(color);return log(color).log(x).log("\x3a\x20").log(c_reset);}template<class...T>logger&operator()(T...value){return log(value...).endl();}template<class...T>logger&_assert(const std::string&file,int line,const std::string&raw,bool value,const std::string&info_str,T...info){if(!value){endl();hint(file,"magenta").hint(line,"magenta").log(c_yellow).log("Assertion `").log(c_yellow_bold).log(raw).log(c_yellow).log("` failed").log(c_reset).endl();if(info_str!="")hint("detail","magenta").hint(info_str)(info...);if(_assert_exit)exit(0);}return*this;}};namespace impl{logger see_logger(std::cout);}}
#ifdef CM_DEBUG
#define see(arg...) cm::impl::see_logger.hint(#arg)(arg)
#define asee(arg...) cm::impl::see_logger.hint(__FILE__, "magenta").hint(__LINE__, "magenta").hint(#arg)(arg)
#define cm_assert(val, arg...) cm::impl::see_logger._assert(__FILE__, __LINE__, #val, val, #arg, ##arg)
#else
#define see(...)
#define asee(...)
#define cm_assert(...)
#endif
#endif
#ifndef CM_SCANNER_H
#define CM_SCANNER_H
#include <cstdio>
#include <cctype>
namespace cm{template<class Type,size_t buf_size>class buffer_reader{protected:FILE*src;Type*const buff;Type*buff_end;Type*buff_pos;void flush(){buff_end=buff+fread(buff,sizeof(Type),buf_size,src);buff_pos=buff;if(buff_end==buff){*buff_end='\0';}}public:buffer_reader(FILE*src):src(src),buff(new Type[buf_size]){flush();}buffer_reader(const buffer_reader&)=delete;buffer_reader(buffer_reader&&)=delete;buffer_reader&operator=(const buffer_reader&)=delete;buffer_reader&operator=(buffer_reader&&)=delete;Type get()const{return*buff_pos;}Type next(){Type result=get();buff_pos++;if(buff_pos==buff_end)flush();return result;}~buffer_reader(){fclose(src);delete[]buff;}};
#ifdef CM_DEBUG
using optimal_reader=buffer_reader<char,1>;
#else
using optimal_reader=buffer_reader<char,1<<16>;
#endif
template<class BufferReader>class scanner:protected BufferReader{private:using BufferReader::get;using BufferReader::next;inline bool is_ws(char c){return c<=' ';}inline bool is_cr(char c){return c=='\n'||c=='\r';}int get_sign(){while(!isdigit(get())&&get()!='-')next();if(get()=='-')return next(),-1;return 1;}public:scanner()=delete;using BufferReader::BufferReader;char next_char(){while(is_ws(get()))next();return next();}char*next_token(char*s){while(is_ws(get()))next();while(!is_ws(get()))*s++=next();*s='\0';return s;}char*next_line(char*s){while(is_ws(get()))next();while(!is_cr(get()))*s++=next();*s='\0';return s;}int next_int(){int sign=get_sign();int result=0;while(isdigit(get()))result=result*10+(next()-'0');return sign*result;}long long next_long(){int sign=get_sign();long long result=0;while(isdigit(get()))result=result*10+(next()-'0');return sign*result;}long long next_modint(long long mod){get_sign();long long result=0;while(isdigit(get()))result=(result*10+(next()-'0'))%mod;return result;}double next_double(){int sign=get_sign();double result=0;while(isdigit(get()))result=result*10+(next()-'0');if(get()=='.'){next();double cur_ep=0.1;while(isdigit(get()))result+=cur_ep*(next()-'0'),cur_ep*=0.1;}return sign*result;}};}
#endif
#ifndef CM_UTIL_H
#define CM_UTIL_H 1
#include <utility>
#include <vector>
namespace cm{template<class T>inline bool check_min(T&a,const T&b){return b<a?a=b,1:0;}template<class T>inline bool check_max(T&a,const T&b){return a<b?a=b,1:0;}struct once_t{bool once=true;bool operator()(){return once?(once=false,true):false;}};}using cm::check_min;using cm::check_max;template<class A,class B>inline __attribute__((always_inline))std::pair<A,B>operator+(const std::pair<A,B>&lhs,const std::pair<A,B>&rhs){return std::make_pair(lhs.first+rhs.first,lhs.second+rhs.second);}template<class A,class B>inline __attribute__((always_inline))std::pair<A,B>operator-(const std::pair<A,B>&lhs,const std::pair<A,B>&rhs){return std::make_pair(lhs.first-rhs.first,lhs.second-rhs.second);}template<class A,class B>inline __attribute__((always_inline))std::pair<A,B>&operator+=(std::pair<A,B>&lhs,const std::pair<A,B>&rhs){lhs.first+=rhs.first;lhs.second+=rhs.second;return lhs;}template<class A,class B>inline __attribute__((always_inline))std::pair<A,B>&operator-=(std::pair<A,B>&lhs,const std::pair<A,B>&rhs){lhs.first-=rhs.first;lhs.second-=rhs.second;return lhs;}template<class T>std::vector<T>&operator+=(std::vector<T>&a,const std::vector<T>&b){a.insert(a.end(),b.begin(),b.end());return a;}template<class T>std::vector<T>&operator+=(std::vector<T>&a,const T&b){a.insert(a.end(),b);return a;}template<class T>std::vector<T>&operator+=(std::vector<T>&a,T&&b){a.insert(a.end(),std::forward<T>(b));return a;}template<class T>std::vector<T>operator+(std::vector<T>a,const std::vector<T>&b){a+=b;return a;}template<class T>std::vector<T>operator+(std::vector<T>a,T&b){a+=b;return a;}template<class T>std::vector<T>operator+(std::vector<T>a,T&&b){a+=std::forward<T>(b);return a;}
#define __AT_INIT(line, Pred) struct CM_INNER_ATINIT##line##_t { \
CM_INNER_ATINIT##line## _t()Pred}CM_INNER_ATINIT##line
#define _AT_INIT(line, Pred) __AT_INIT(line, Pred)
#define AT_INIT(Pred) _AT_INIT(__LINE__, Pred)
#define __AT_EXIT(line, Pred) struct CM_INNER_ATEXIT##line##_t { \
~CM_INNER_ATEXIT##line## _t()Pred}CM_INNER_ATEXIT##line
#define _AT_EXIT(line, Pred) __AT_EXIT(line, Pred)
#define AT_EXIT(Pred) _AT_EXIT(__LINE__, Pred)
#endif
// #include "/home/jack/cm/intm"
// #include "/home/jack/cm/string"

cm::scanner<cm::optimal_reader> sc(stdin);

constexpr int N = 500005;

struct node_t
{
  node_t *f = nullptr, *s[2] = {nullptr, nullptr};
  bool rev = false; 
  int val = 1e6, min = val;
  int cover = 0, max_cover, add = 0;
  int weigh = 0, max_weigh;

  bool is_root() { return f==nullptr || (f->s[0] != this && f->s[1] != this); }
  bool get_son() { return f->s[1] == this; }
  void push_up() { min = val; max_cover = cover; max_weigh = weigh;
    if (s[0]) check_min(min, s[0]->min), check_max(max_cover, s[0]->max_cover), check_max(max_weigh, s[0]->max_weigh);
    if (s[1]) check_min(min, s[1]->min), check_max(max_cover, s[1]->max_cover), check_max(max_weigh, s[1]->max_weigh); }
  void push_add(int delta) { cover += weigh ? delta : 0; max_cover += max_weigh ? delta : 0; add += delta; }
  void push_rev() { rev ^= 1; std::swap(s[0], s[1]); }
  void push_down() {
    if (rev) { if (s[0]) s[0]->push_rev(); if (s[1]) s[1]->push_rev(); rev = false; }
    if (add) { if (s[0]) s[0]->push_add(add); if (s[1]) s[1]->push_add(add); add = 0; } }
  void push() { if (!is_root()) f->push(); push_down(); }

  void rotate() { 
    node_t *uu=this, *ff=f, *aa=ff->f;
    bool ss = get_son(); 
    if (!ff->is_root()) aa->s[ff->get_son()] = uu;
    ff->f = uu; ff->s[ss] = uu->s[!ss];
    uu->f = aa; uu->s[!ss] = ff;
    if (ff->s[ss]) ff->s[ss]->f = ff;
    ff->push_up(); uu->push_up(); }
  void splay() { push();
    while (!is_root()) { if (f->is_root()) { rotate(); break; }
      (f->get_son() == get_son() ? f : this)->rotate(); rotate(); } }
  void access() { node_t *uu = this, *ss = nullptr;
    while (uu != nullptr) { 
      uu->splay(); uu->s[1] = ss; uu->push_up();
      ss = uu; uu = uu->f; } }
  void make_root() { access(); splay(); push_rev(); }
  node_t *find_root() {
    access(); splay(); node_t *uu = this; uu->push_down();
    while (uu->s[0]) { uu = uu->s[0]; uu->push_down(); } 
    uu->splay(); return uu; }
};

node_t p[N * 2];
int u[N], v[N];
int n, m;
bool is_te[N];

void add_edge(int id)
{
  is_te[id] = true;
  int eid = n + id;
  see("add_edge", id, u[id], v[id]);
  p[eid].val = p[eid].min = id; p[eid].weigh = 1;
  p[u[id]].make_root(); p[u[id]].splay(); p[u[id]].f = &p[eid];
  p[v[id]].make_root(); p[v[id]].splay(); p[v[id]].f = &p[eid];
}

std::pair<int,int> query_cover(int u, int v)
{
  p[u].make_root(); p[v].access(); p[v].splay();
  see("query", u, v, p[v].max_cover, p[v].min);
  return std::make_pair(p[v].max_cover, p[v].min);
}

void cover(int id, int delta)
{
  int u = ::u[id], v = ::v[id];
  see("cover", id, u, v, delta);
  p[u].make_root(); p[v].access(); p[v].splay();
  p[v].push_add(delta);
}

void erase_edge(int id)
{
  see("erase_edge", id, u[id], v[id]);
  cm_assert(p[u[id]].find_root() == p[v[id]].find_root());
  is_te[id] = false;
  int eid = n + id;
  p[u[id]].make_root(); p[eid].access(); p[eid].splay(); p[eid].s[0] = p[u[id]].f = nullptr; p[eid].push_up();
  p[v[id]].make_root(); p[eid].access(); p[eid].splay(); p[eid].s[0] = p[v[id]].f = nullptr; p[eid].push_up();
}

int main()
{
  n = sc.next_int(); m = sc.next_int();
  for (int i = 1; i <= m; i++) 
    u[i] = sc.next_int(), v[i] = sc.next_int();

  long long ans = 0;

  int l = 1;
  for (int r = 1; r <= m; r++)
  {
    int u = ::u[r], v = ::v[r];

restart:
    see(l, r);
    auto ru = p[u].find_root(), rv = p[v].find_root();
    see(ru, rv);
    if (ru != rv)
      add_edge(r);
    else 
    {
      auto [c,id] = query_cover(u, v);
      if (c == 0)
      {
        erase_edge(id);   
        add_edge(r);
        cover(id, 1);
      }
      else
      {
        if (is_te[l])
          erase_edge(l);
        else
          cover(l, -1);
        l++;
        goto restart;
      }
    }

    ans += r - l + 1;
  }

  std::cout << ans << std::endl;
  return 0;
}