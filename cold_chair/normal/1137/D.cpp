#include<cstdio> 
#include<cstring>
#define pp printf
#define ll long long
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define fl fflush(stdout)
using namespace std;

char s[12];
int D, bl[10];

void read() {
	scanf("%d", &D);
	fo(i, 1, D) {
		scanf("%s", s);
		ff(j, 0, strlen(s)) bl[s[j] - '0'] = i;
	}
}

int main() {
	do {
		pp("next 0\n"); fl; read();
		pp("next 0 1\n"); fl; read();
	} while(bl[0] != bl[1]);
	do {
		pp("next 0 1 2 3 4 5 6 7 8 9\n"); fl;
		read();
	} while(D != 1);
	pp("done"); fl;
}