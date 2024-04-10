#include<bits/stdc++.h>
using namespace std;

int md(int a,int b,int c){
    int aa[3]={a,b,c};
    sort(aa,aa+3);
    if(a==c&&b==c)return 0;
    if(aa[0]+1==aa[1]&&aa[1]+1==aa[2])return 0;
    if(a==c||b==c||a==b)return 1;
    if(abs(a-c)==1||abs(a-b)==1||abs(b-c)==1||abs(a-c)==2||abs(a-b)==2||abs(b-c)==2)return 1;
    return 2;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a,b,c;
    char d,e,f;
    cin>>a>>d>>b>>e>>c>>f;
    if(d!=e&&e!=f&&d!=f){
        cout<<2<<endl;
        return 0;
    }
    if(d==e&&e==f){
        cout<<md(a,b,c)<<endl;
        return 0;
    }
    int ans=2;
    if(d==e){
        for(int i=1;i<10;i++){
            ans=min(ans,md(a,b,i)+1);
        }
    }
    if(f==e){
        for(int i=1;i<10;i++){
            ans=min(ans,md(c,b,i)+1);
        }
    }
    if(f==d){
        for(int i=1;i<10;i++){
            ans=min(ans,md(a,c,i)+1);
        }
    }
    cout<<ans<<endl;

    return 0;
}