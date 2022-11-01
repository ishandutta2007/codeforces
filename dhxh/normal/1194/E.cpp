#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
    #include <iostream>
    #include <cstdio>
    #include <cstdlib>
    #include <cmath>
    #include <cstring>
    #include <string>
    #include <algorithm>
    #include <vector>
    #include <bitset>
     
    using namespace std;
     
    int n, m, t;
     
    int M = 5001;
     
    struct ex {
    	int a, b, x, y;
    };
     
    vector <ex> vecr;
    vector <ex> vecc;
     
    bitset<5000> f[5005];
     
    int read(){
    	int x;
    	scanf("%d", &x);
    	return x;
    }
     
    int main(){
    	int i, j;
    	long long ans = 0;
    	int a, b, x, y;
    	
    	n = read();
    	
    	for(i=1;i<=n;i++){
    		a = read();
    		b = read();
    		x = read();
    		y = read();
    		
    		if(b > y)swap(b, y);
    		if(a > x)swap(a, x);
    		
    		if(a == x){
    			vecc.push_back({a, b, x, y});
    		}else{
    			vecr.push_back({a, b, x, y});
    		}
    	}
    	
    	for(j=0;j<vecr.size();j++){
    		for(i=0;i<vecc.size();i++){
    			if(vecr[j].a <= vecc[i].a and vecc[i].a <= vecr[j].x and vecc[i].b <= vecr[j].b and vecr[j].b <= vecc[i].y){
    				f[j][i] = 1;
    			}
    		}
    		for(i=0;i<j;i++){
    			long long tmp = (f[i] & f[j]).count();
    			ans += tmp * (tmp - 1) / 2;
    		}
    	}
    	
    	/*for(i=0;i<vecr.size();i++){
    		for(j=i+1;j<vecr.size();j++){
    			long long tmp = (f[i] & f[j]).count();
    			ans += tmp * (tmp - 1) / 2;
    		}
    	}*/
    	
    	printf("%lld\n", ans);
    	
    	return 0;
    }