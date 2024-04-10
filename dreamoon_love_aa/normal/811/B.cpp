#include<bits/stdc++.h>
using namespace std;
#define SZ(X) (X).size()
#define W(X) cout<<X<<endl
int main(){
   int n,m,p[10010];
   cin >> n >> m;
   for(int i = 1; i <= n; i++){
        cin >> p[i];
   }
   while(m--){
        int l,r,x;
        cin >> l >> r >> x;
        if(l == r)
            W("Yes");
        else{
            int less = 0;
            for(int i = l; i <= r; i++){
                if(p[i] < p[x])
                    less++;
            }
            if(x - l == less)
                W("Yes");
            else
                W("No");
        }
   }
   return 0;
}