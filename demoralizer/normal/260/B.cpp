#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
#define r0 return 0
int check(char* c){
    if((c[2]!='-')||(c[5]!='-')||(c[6]!='2')||(c[7]!='0')||(c[8]!='1')||(c[9]<'3')||(c[9]>'5'))return 0;
    if((c[0]<'0')||(c[0]>'3'))return 0;
    if((c[1]<'0')||(c[1]>'9'))return 0;
    if((c[3]<'0')||(c[3]>'1'))return 0;
    if((c[4]<'0')||(c[4]>'9'))return 0;
    int d=10*(c[0]-'0')+c[1]-'0',m=10*(c[3]-'0')+c[4]-'0';
    if(m>12||m<1)return 0;
    int k;
    switch(m){
        case 1:case 3:case 5:case 7:case 8:case 10:case 12:
            k=31;break;
        case 2:
            k=28;break;
        default:
            k=30;
    }
    if(d>k||d<1)return 0;
    return 1;
}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    char c[100005];
    map<string,int> m;
    cin>>c;
    string s=c;
    int l=strlen(c);
    for(int i=0;i<l-9;i++){
        if(check(c+i)){
            m[s.substr(i,10)]++;
        }
    }
    int z=0;string a;
    for(auto i=m.begin();i!=m.end();i++){
        if(i->sc>z){z=i->sc;a=i->fr;}
    }
    cout<<a;
}