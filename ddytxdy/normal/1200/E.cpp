    #include<cmath>
    #include<cstdio>
    #include<cstring>
    #include<iostream>
    #include<algorithm>
    using namespace std; 
    const int N = 1e6 + 50,mod=1003020631,base=97;
    int n,len,ll,hsh1[N],hsh2[N],pw[N]; char a[N],b[N];
    bool check(int x) {
    	int x1 = hsh2[x];
    	int x2 = ((hsh1[ll] - 1ll * hsh1[ll - x] * pw[x]) % mod + mod) % mod;
    	return x1 == x2;
    }
    int main() {
    	scanf("%d", &n);
    	pw[0] = 1;
    	for (int i = 1; i <= 1e6; i++)pw[i] = 1ll * pw[i - 1] * base % mod;
    	for (int i = 1; i <= n; i++) {
    		scanf("%s", b+1);
    		len = strlen(b + 1);
    		for (int j = 1; j <= len; j++)hsh2[j] = (1ll * hsh2[j - 1] * base + b[j] - '0' + 1) % mod;
    		int pp;
    		for (pp = len; pp; pp--) if (ll >= pp && check(pp))break;
    		for (int j = pp + 1; j <= len; j++) {
    			a[++ll]=b[j];
    			hsh1[ll] = (1ll * hsh1[ll - 1] * base + b[j] - '0' + 1) % mod;
    		}
    	}
    	printf("%s", a + 1);
    	return 0;
    }