#include<bits/stdc++.h>
using namespace std;
const int maxn=125;
char mp[125][125];
int main() {
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	a--,b--,c--,d--;
	int pos=1,k=1;
	while(d) {
		if(d>=12) {
			if(k==1) {
				for(int i=1; i<25; i+=2)
					mp[pos][i]='D';
				pos+=2;
				d-=12;
				k--;
			} else if(k==0) {
				for(int i=2; i<=25; i+=2)
					mp[pos][i]='D';
				pos+=2;
				d-=12;
				k++;
			}
		} else {
			if(k==1) {
				for(int i=1; i<1+d*2; i+=2)
					mp[pos][i]='D';
				d=0;
			}
			if(k==0) {
				for(int i=2; i<2+d*2; i+=2)
					mp[pos][i]='D';
				d=0;
			}
		}
	}
	pos = 1;
	k=1;
	while(c) {
		if(c>=12) {
			if(k==1) {
				for(int i=26; i<50; i+=2)
					mp[pos][i]='C';
				pos+=2;
				c-=12;
				k--;
			} else if(k==0) {
				for(int i=27; i<=50; i+=2)
					mp[pos][i]='C';
				pos+=2;
				c-=12;
				k++;
			}
		} else {
			if(k==1) {
				for(int i=26; i<26+c*2; i+=2)
					mp[pos][i]='C';
				c=0;
			}
			if(k==0) {
				for(int i=27; i<27+c*2; i+=2)
					mp[pos][i]='C';
				c=0;
			}
		}
	}
	pos = 26;
	k=1;
	while(b) {
		if(b>=12) {
			if(k==1) {
				for(int i=1; i<25; i+=2)
					mp[pos][i]='B';
				pos+=2;
				b-=12;
				k--;
			} else if(k==0) {
				for(int i=2; i<=25; i+=2)
					mp[pos][i]='B';
				pos+=2;
				b-=12;
				k++;
			}
		} else {
			if(k==1) {
				for(int i=1; i<1+b*2; i+=2)
					mp[pos][i]='B';
				b=0;
			}
			if(k==0) {
				for(int i=2; i<1+b*2; i+=2)
					mp[pos][i]='B';
				b=0;
			}
		}
	}
	pos = 26;
	k=1;
	while(a) {
		if(a>=12) {
			if(k==1) {
				for(int i=26; i<50; i+=2)
					mp[pos][i]='A';
				pos+=2;
				a-=12;
				k--;
			} else if(k==0) {
				for(int i=27; i<=50; i+=2)
					mp[pos][i]='A';
				pos+=2;
				a-=12;
				k++;
			}
		} else {
			if(k==1) {
				for(int i=26; i<26+a*2; i+=2)
					mp[pos][i]='A';
				a=0;
			}
			if(k==0) {
				for(int i=27; i<27+a*2; i+=2)
					mp[pos][i]='A';
				a=0;
			}
		}
	}
	printf("50 50\n");
	for(int i=1; i<=50; i++) {
		for(int j=1; j<=50; j++) {
			if(i<=25&&j<=25) {
				if(mp[i][j]=='D') printf("%c",mp[i][j]);
				else printf("A");
			}
			if(i<=25&&j>25) {
				if(mp[i][j]=='C') printf("%c",mp[i][j]);
				else printf("B");
				if(j==50) printf("\n");
			}
			if(i>25&&j<=25) {
				if(mp[i][j]=='B') printf("%c",mp[i][j]);
				else printf("C");

			}
			if(i>25&&j>25) {
				if(mp[i][j]=='A') printf("%c",mp[i][j]);
				else printf("D");
				if(j==50) printf("\n");
			}
		}
	}
	return 0;
}