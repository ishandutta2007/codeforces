#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e6 + 5;

struct kmp{
	int n, m;
	char a[maxn];
	char b[maxn];
	int Next[maxn];

	int getnext(){
		int i, j;
		
		Next[0] = 0;
		Next[1] = 0;
		
		for(i=2;i<=m;i++){
			j = Next[i - 1];
			while(j and b[j + 1] != b[i]){
				j = Next[j];
			}
			
			if(b[j + 1] == b[i]){
				Next[i] = j + 1;
			}else{
				Next[i] = 0;
			}
		}
			
		return 0;
	}

	int check(){
		int i, j;
		m = strlen(b) - 1;
		
		getnext();
		
		for(i=max(1, n - m + 1),j=0;i<=n;i++){
			if(a[i] != b[j + 1]){
				j = Next[j];
				while(j and a[i] != b[j + 1]){
					j = Next[j];
				}
			}
			if(a[i] == b[j + 1]){
				j++;
			}
		}
		
			for(i=j+1;i<=m;i++){
			a[++n] = b[i];
		}
		
		return 0;
	}
	
	kmp(){n = 0, a[0] = '0', b[0] = '0';};
} s;

int n, m, t;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	n = read();
	
	scanf("%s", &s.a[1]);
	s.n = strlen(s.a) - 1;
	
	for(i=2;i<=n;i++){
		scanf("%s", &s.b[1]);
		s.check();
	}
	
	printf("%s\n", &s.a[1]);
	
	return 0;
}