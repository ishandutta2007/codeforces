#include <bits/stdc++.h>
using namespace std;


string s;
bool win,lose;
int n,m;
struct st{
    int a[26];
};
int sz;
bool t[2000005];
st q[2000005];
void build(int x,int y,string s){
    if (y==s.size()+1) return;
    int z=s[y-1]-'a';
    if (q[x].a[z]==0) q[x].a[z]=++sz;
    build(q[x].a[z],y+1,s);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>s;
        build(0,1,s);
    }
    for (int i=sz;i>=0;--i) {
        t[i]=false;
        for (int j=0;j<26;++j){
            int to=q[i].a[j];
            if (to!=0 && t[to]==false) {
                t[i]=true;
                break;
            }
        }
    }
    if (t[0]) win=true;
    for (int i=sz;i>=0;--i) {
        t[i]=false;
        bool k=false;
        for (int j=0;j<26;++j){
            int to=q[i].a[j];
            if (to!=0) k=true;
            if (to!=0 && t[to]==false) {
                t[i]=true;
                break;
            }
        }
        if (k==false) t[i]=true;
    }
    if (t[0]) lose=true;
    if ((win && lose) || (win==true && lose==false && m%2==1) )cout<<"First";
    else cout<<"Second";

}