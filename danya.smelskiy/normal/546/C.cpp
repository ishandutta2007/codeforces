#include <bits/stdc++.h>
using namespace std;

vector<int> v,v2;
int n,n1,n2,x,number,ans;
bool t;
string s;
map<string,bool > used;

string takestring(int x){
    string ss;
    int y=0;
    while (x>0){
        y=x%10;
        if (y==0) ss="0"+ss;
        if (y==1) ss="1"+ss;
        if (y==2) ss="2"+ss;
        if (y==3) ss="3"+ss;
        if (y==4) ss="4"+ss;
        if (y==5) ss="5"+ss;
        if (y==6) ss="6"+ss;
        if (y==7) ss="7"+ss;
        if (y==8) ss="8"+ss;
        if (y==9) ss="9"+ss;
        x/=10;
    }
    //cout<<ss<<endl;
    return ss;
}
string getstring(){
    string ss;
    for (int i=0;i<v.size();++i){
            ss=ss+takestring(v[i]);
    }
    ss=ss+"-";
    for (int i=0;i<v2.size();++i){
            ss=ss+takestring(v2[i]);
    }
    //cout<<ss<<endl;
    return ss;
}
void recurs(){
    if (v.size()==0){
        number=2;
        return;
    }
    if (v2.size()==0){
        number=1;
        return;
    }
    ++ans;
    int x,y;
    x=v[0];
    y=v2[0];
    if (x>y){
        v.erase(v.begin()+0);
        v2.erase(v2.begin()+0);
        v.push_back(y);
        v.push_back(x);
    } else {
        v.erase(v.begin()+0);
        v2.erase(v2.begin()+0);
        v2.push_back(x);
        v2.push_back(y);
    }
    string sk=getstring();
    if (used[sk]==true){
        t=true;
        return;
    }
    used[sk]=true;
    recurs();
}
int main(){
    cin>>n;
    cin>>n1;
    for (int i=1;i<=n1;++i){
        cin>>x;
        v.push_back(x);
    }
    cin>>n2;
    for (int i=1;i<=n2;++i){
        cin>>x;
        v2.push_back(x);
    }
    s=getstring();
    used[s]=true;
    recurs();
    if (t==true) cout<<"-1";
    else cout<<ans<<" "<<number;
}