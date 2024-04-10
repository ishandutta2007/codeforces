//  228

#include <bits/stdc++.h>
using namespace std;

int pa[111];
int fp(int x){
    if(pa[x] == x) return x;
    return pa[x] = fp(pa[x]);
}
int use[111];
int main(){
    int n,m,a,b;
    cin >> n >> m;
    int cou=0;
    for(int i = 1;i<=n;i++){
       pa[i] = i;
    }
    int no = 0;
    int hav= 0;
    for(int i = 1;i<=m;i++){
        cin >> a >> b;
        if(pa[fp(a)] == fp(b)){
            hav++;
            if(use[fp(b)] == 1){
                no = 1;
            }
            use[fp(b)] = 1;
        }
        pa[fp(a)] = fp(b);
    }
    int p = fp(1);
    for(int i = 1;i<=n;i++){
        if(fp(i) != p) no = 1;
    }
    if(!no && hav == 1) cout << "FHTAGN!";
    else cout << "NO";


}