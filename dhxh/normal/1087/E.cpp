#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e6 + 5;

int n, m, t, k;

char s[maxn];
char a[maxn];
char b[maxn];

bool visa[35];
bool visb[35];
char ans[35];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int printans(){
	int i, j;
	
	for(i=0;i<k;i++){
		if(!visa[i]){
			for(j=0;j<k;j++){
				if(!visb[j]){
					ans[i] = j + 'a';
					visa[i] = true;
					visb[j] = true;
					break;
				}
			}
		}
	}
	
	printf("YES\n");
	
	for(i=0;i<k;i++){
		printf("%c", ans[i]);
	}
	printf("\n");
	
	return 0;
}

bool checka(int i){
	bool va[35];
	bool vb[35];
	char ansa[35];
	int j, l;
	
	for(j=0;j<=k;j++){
		va[j] = visa[j];
		vb[j] = visb[j];
		ansa[j] = ans[j];
	}
	
	for(;i<n;i++){
		if(!va[s[i] - 'a']){
			for(j=a[i]-'a'+1;j<k;j++){
				if(!vb[j]){
					va[s[i] - 'a'] = true;
					vb[j] = true;
					ansa[s[i] - 'a'] = j + 'a';
					for(l=0;l<=k;l++){
						visa[l] = va[l];
						visb[l] = vb[l];
						ans[l] = ansa[l];
					}
					printans();
					return true;
				}
			}
			
			if(!vb[a[i] - 'a']){
				va[s[i] - 'a'] = true;
				vb[a[i] - 'a'] = true;
				ansa[s[i] - 'a'] = a[i];
			}else{
				return false;
			}
		}else{
			if(ansa[s[i] - 'a'] > a[i]){
				for(l=0;l<=k;l++){
					visa[l] = va[l];
					visb[l] = vb[l];
					ans[l] = ansa[l];
				}
				printans();
				return true;
			}
			if(ansa[s[i] - 'a'] < a[i]){
				return false;
			}
		}
	}
	
	for(l=0;l<=k;l++){
		visa[l] = va[l];
		visb[l] = vb[l];
		ans[l] = ansa[l];
	}
	printans();
	
	return true;
}

bool checkb(int i){
	bool va[35];
	bool vb[35];
	char ansa[35];
	int j, l;
	
	for(j=0;j<=k;j++){
		va[j] = visa[j];
		vb[j] = visb[j];
		ansa[j] = ans[j];
	}
	
	for(;i<n;i++){
		if(!va[s[i] - 'a']){
			for(j=b[i]-'a'-1;j>=0;j--){
				if(!vb[j]){
					va[s[i] - 'a'] = true;
					vb[j] = true;
					ansa[s[i] - 'a'] = j + 'a';
					for(l=0;l<=k;l++){
						visa[l] = va[l];
						visb[l] = vb[l];
						ans[l] = ansa[l];
					}
					printans();
					return true;
				}
			}
			
			if(!vb[b[i] - 'a']){
				va[s[i] - 'a'] = true;
				vb[b[i] - 'a'] = true;
				ansa[s[i] - 'a'] = b[i];
			}else{
				return false;
			}
		}else{
			if(ansa[s[i] - 'a'] > b[i]){
				return false;
			}
			
			if(ansa[s[i] - 'a'] < b[i]){
				for(l=0;l<=k;l++){
					visa[l] = va[l];
					visb[l] = vb[l];
					ans[l] = ansa[l];
				}
				printans();
				return true;
			}
		}
	}
	
	for(l=0;l<=k;l++){
		visa[l] = va[l];
		visb[l] = vb[l];
		ans[l] = ansa[l];
	}
	printans();
	
	return true;
}

int solve(){
	int i, j;
	
	for(i=0;i<n;i++){
		if(a[i] == b[i]){
			if(!visa[s[i] - 'a']){
				if(!visb[a[i] - 'a']){
					visa[s[i] - 'a'] = true;
					visb[a[i] - 'a'] = true;
					ans[s[i] - 'a'] = a[i];
				}else{
					if(ans[s[i] - 'a'] != a[i]){
						printf("NO\n");
						return 0;
					}
				}
			}else{
				if(ans[s[i] - 'a'] != a[i]){
					printf("NO\n");
					return 0;
				}
			}
		}else{
			if(!visa[s[i] - 'a']){
				for(j=a[i]-'a'+1;j<=b[i]-'a'-1;j++){
					if(!visb[j]){
						visa[s[i] - 'a'] = true;
						visb[j] = true;
						ans[s[i] - 'a'] = j + 'a';
						printans();
						return 0;
					}
				}
				
				if(!visb[a[i] - 'a']){
					visa[s[i] - 'a'] = true;
					visb[a[i] - 'a'] = true;
					ans[s[i] - 'a'] = a[i];
					if(checka(i + 1)){
						return 0;
					}
					visa[s[i] - 'a'] = false;
					visb[a[i] - 'a'] = false;
					ans[s[i] - 'a'] = 0;
				}
				
				if(!visb[b[i] - 'a']){
					visa[s[i] - 'a'] = true;
					visb[b[i] - 'a'] = true;
					ans[s[i] - 'a'] = b[i];
					if(checkb(i + 1)){
						return 0;
					}
				}
				
				printf("NO\n");
				return 0;
			}else{
				if(a[i] > ans[s[i] - 'a'] or ans[s[i] - 'a'] > b[i]){
					printf("NO\n");
					return 0;
				}else{
					if(a[i] < ans[s[i] - 'a'] and ans[s[i] - 'a'] < b[i]){
						printans();
						return 0;
					}else if(a[i] == ans[s[i] - 'a'] and ans[s[i] - 'a'] < b[i]){
						if(checka(i + 1)){
							return 0;
						}
						printf("NO\n");
						return 0;
					}else if(a[i] < ans[s[i] - 'a'] and b[i] == ans[s[i] - 'a']){
						if(checkb(i + 1)){
							return 0;
						}
						printf("NO\n");
						return 0;
					}
				}
			}
		}
	}
	
	printans();
	
	return 0;
}

int main(){
	int i, j;
	
	t = read();
	
	while(t--){
		k = read();
		scanf("%s", s);
		scanf("%s", a);
		scanf("%s", b);
		n = strlen(s);
		memset(visa, 0, sizeof(visa));
		memset(visb, 0, sizeof(visb));
		memset(ans, 0, sizeof(ans));
		
		solve();
	}
	
	return 0;
}