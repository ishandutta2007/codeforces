#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
#define r0 return 0
int n,m;
set<int> v[16];
set<int> final,temp,kept,disc;
map<int,int> rem;
void brute(){
    set<int> avail;
    for(set<int>::iterator i=temp.begin();i!=temp.end();i++){
        if(rem.find(*i)!=rem.end())continue;
        if(kept.find(*i)!=kept.end())continue;
        if(disc.find(*i)!=disc.end())continue;
        kept.insert(*i);
        avail.insert(*i);
        for(set<int>::iterator j=v[*i].begin();j!=v[*i].end();j++){
            if(disc.find(*j)!=disc.end())continue;
            rem[*j]++;
        }
        if(n==(rem.size()+kept.size()+disc.size())){
            if(kept.size()>final.size()){
                final.clear();
                final=kept;
            }
        }
        else{
            brute();
        }
        for(set<int>::iterator j=v[*i].begin();j!=v[*i].end();j++){
            if(disc.find(*j)!=disc.end())continue;
            rem[*j]--;
            if(rem[*j]==0)rem.erase(*j);
        }
        kept.erase(*i);
        disc.insert(*i);
    }
    for(set<int>::iterator i=avail.begin();i!=avail.end();i++){
        disc.erase(*i);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n>>m;
    map<string,int> z;
    string s,t,q[n];
    for(int i=0;i<n;i++){
        cin>>s;
        z[s]=i;
        q[i]=s;
        temp.insert(i);
    }
    for(int i=0;i<m;i++){
        cin>>s>>t;
        v[z[s]].insert(z[t]);
        v[z[t]].insert(z[s]);
    }
    brute();
    cout<<final.size()<<"\n";
    for(map<string,int>::iterator i=z.begin();i!=z.end();i++){
        if(final.find(i->sc)!=final.end())
            cout<<(i->fr)<<"\n";
    }
}