#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    while(n--){
        string a,b,c;
        cin>>a>>b>>c;
        bool work=true;
        for(int i=0;i<(int)c.size();i++){
            if(a[i]==c[i]||b[i]==c[i]){

            }
            else work=false;
        }
        if(work)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}