#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AMT 300001
#define UND 1234567898
#define LL "%I64d"

int usbPrices[AMT];
int ps2Prices[AMT];
int allPrices[AMT*2];
long long int totalCost;
int a,b,c, priceListLength, usbLength, ps2Length, allLength;

int cmpr(const void* a, const void* b);
int min(int a, int b);
void clr();

int main()
{
	clr();
	scanf("%d %d %d", &a, &b, &c);
	scanf("%d", &priceListLength);

	int temp;
	char ch;
	for(int i=0;i<priceListLength;++i)
	{
		scanf("%d %c", &temp, &ch);
		if(ch == 'U') {
			usbPrices[usbLength] = temp;
			++usbLength;
		}
		else if(ch == 'P') {
			ps2Prices[ps2Length] = temp;
			++ps2Length;
		}
		while(scanf("%c", &ch) && i != priceListLength-1)
		{
			if(ch == '\n')
				break;
		}
	}

	qsort(usbPrices, usbLength, sizeof(int), cmpr);
	qsort(ps2Prices, ps2Length, sizeof(int), cmpr);

	int minUSB = min(usbLength, a);
	int minPS2 = min(ps2Length, b);

	for(int i=0;i<minUSB;++i)
	{
		totalCost += usbPrices[i];
	}
	for(int i=0;i<minPS2;++i)
	{
		totalCost += ps2Prices[i];
	}

	int acount = 0;
	for(int i=minUSB;i<usbLength;++i)
	{
		allPrices[acount] = usbPrices[i];
		++acount;
	}
	for(int i=minPS2;i<ps2Length;++i)
	{
		allPrices[acount] = ps2Prices[i];
		++acount;
	}

	qsort(allPrices, acount, sizeof(int), cmpr);

	int minC = min(acount, c);

	for(int i=0;i<minC;++i)
	{
		totalCost += allPrices[i];
	}

	int supplied = minUSB + minPS2 + minC;

	printf("%d ", supplied);
	printf(LL, totalCost);
	printf("\n");

	return 0;
}

int cmpr(const void* a, const void* b) {
	return  *((int *) a) - *((int*) b);
}

void clr() {
	memset(usbPrices, UND, sizeof(usbPrices));
	memset(ps2Prices, UND, sizeof(ps2Prices));
	memset(allPrices, UND, sizeof(allPrices));
	totalCost = 0;
	usbLength = 0;
	ps2Length = 0;
}
int min(int a, int b) {
	return (a < b) ? a : b;
}