#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
#define r0 return 0
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string me,x,y,c;
    cin>>me;
    int n,z=0;
    cin>>n;getline(cin,c);
    map<string,int> m;
    for(int i=0;i<n;i++){
        int s=0,k=1;
        getline(cin,c);
        int l=c.size();
        x.clear();y.clear();
        for(int i=0;i<l;i++){
            if(c.at(i)=='\'')k=0;
            if(k)y+=c.at(i);
            if(c.at(i)==' '){s++;if(k)y.clear();}
            if(s==0)x+=c.at(i);
        }
        if(s==3){
            if(x==me)m[y]+=5;
            else if(y==me)m[x]+=5;
            else {m[x]+=0;m[y]+=0;}
        }
        else if(c.at(l-1)=='l'){
            if(x==me)m[y]+=15;
            else if(y==me)m[x]+=15;
            else {m[x]+=0;m[y]+=0;}
        }
        else{
            if(x==me)m[y]+=10;
            else if(y==me)m[x]+=10;
            else {m[x]+=0;m[y]+=0;}
        }
    }
    set<pair<int,string> > s;
    for(map<string,int>::iterator i=m.begin();i!=m.end();i++){
        s.insert({-i->sc,i->fr});
    }
    for(set<pair<int,string> >::iterator i=s.begin();i!=s.end();i++){
        cout<<(*i).sc<<"\n";
    }
}