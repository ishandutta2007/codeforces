#include <cstdio>
using namespace std;
typedef long long int lli;
#ifdef ONLINE_JUDGE
#define LLI_FORMAT "%I64d"
#else
#define LLI_FORMAT "%lld"
#endif

int bitLength(lli n){ // nonnegative pl0x
	int shifts = 0;
	while (n > 0) { n >>= 1; shifts++; }
	return shifts;
}

int countFixedLengthPeriodic(int bitlen, lli lower, lli upper){
	int period[65];
	lli count[65];
	lli pie[65];
	int pc = 0;

	for (int plen = bitlen - 1; plen >= 1; plen--){
		if (bitlen % plen == 0){
			period[pc] = plen;
			int copies = bitlen / plen;
			lli x = 1;
			lli mask = 0;
			for (int c = 0; c < copies; c++){
				mask |= x;
				x <<= plen;
			}
			lli lowerCoef = (lower + mask - 1) / mask;
			lli upperCoef = upper / mask;
			count[pc] = (upperCoef - lowerCoef + 1);
			lli piemult = 1;
			for (int i = 0; i < pc; i++){
				if (period[i] % plen == 0){
					piemult -= pie[i];
				}
			}
			pie[pc] = piemult;

			pc++;
		}
	}
	lli finalCount = 0;
	for (int i = 0; i < pc; i++){
		finalCount += count[i] * pie[i];
	}
	return finalCount;
}

lli upperBound(int bitLength){
	lli mask = 0;
	for (int c = 0; c < bitLength; c++){
		mask <<= 1;
		mask |= 1;
	}
	return mask;
}
lli lowerBound(int bitLength){
	lli mask = 1;
	return mask << (bitLength - 1);
}

lli countPeriodic(lli lower, lli upper){
	int lbl = bitLength(lower);
	int ubl = bitLength(upper);
	if (lbl == ubl) return countFixedLengthPeriodic(lbl, lower, upper);

	lli count = 0;
	count += countFixedLengthPeriodic(lbl, lower, upperBound(lbl));
	for (int bitlen = lbl + 1; bitlen < ubl; bitlen++){
		count += countFixedLengthPeriodic(bitlen, lowerBound(bitlen), upperBound(bitlen));
	}
	count += countFixedLengthPeriodic(ubl, lowerBound(ubl), upper);
	return count;
}

int main(){
	lli lower, upper;
	scanf(LLI_FORMAT, &lower);
	scanf(" ");
	scanf(LLI_FORMAT, &upper);
	printf(LLI_FORMAT, countPeriodic(lower, upper));
}