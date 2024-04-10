#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define MM 998244353
#define fr first
#define sc second
#define vc vector
#define pii pair<int,int>
#define msi map<string,int>
#define mii map<int,int>
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int xa,ya,xb,yb,xc,yc;
    cin>>xa>>ya>>xb>>yb>>xc>>yc;
    pii z[3];
    set<pii> v;
    v.insert({xa,ya});v.insert({xb,yb});v.insert({xc,yc});
    int pab,pbc,pca,p;
    p=abs(xa-xb)+abs(ya-yb)-1;

    set<pii>::iterator j=v.begin();
    xa=(*j).fr;ya=(*j).sc;j++;
    xc=(*j).fr;yc=(*j).sc;j++;
    xb=(*j).fr;yb=(*j).sc;
    if((yc>=ya&&yc<=yb)||(yc<=ya&&yc>=yb)){
        p-=1;
        for(int i=min(xa,xc);i<=max(xa,xc);i++){
            v.insert({i,ya});
        }
        for(int i=min(ya,yc);i<=max(ya,yc);i++){
            v.insert({xc,i});
        }
        for(int i=min(xb,xc);i<=max(xb,xc);i++){
            v.insert({i,yb});
        }
        for(int i=min(yb,yc);i<=max(yb,yc);i++){
            v.insert({xc,i});
        }
    }
    else{
        p+=min(abs(ya-yc),abs(yb-yc))-1;
        if(abs(ya-yc)<abs(yb-yc)){
            for(int i=min(xa,xb);i<=max(xa,xb);i++){
                v.insert({i,ya});
            }
            for(int i=min(ya,yb);i<=max(ya,yb);i++){
                v.insert({xb,i});
            }
            for(int i=min(ya,yc);i<=max(ya,yc);i++){
                v.insert({xc,i});
            }
        }
        else{
            for(int i=min(xa,xb);i<=max(xa,xb);i++){
                v.insert({i,yb});
            }
            for(int i=min(ya,yb);i<=max(ya,yb);i++){
                v.insert({xa,i});
            }
            for(int i=min(yb,yc);i<=max(yb,yc);i++){
                v.insert({xc,i});
            }
        }
    }
    p+=3;
    //if(p!=v.size()){while(1==1){p++;}}
    cout<<(v.size())<<"\n";
    while(!v.empty()){
        /*
        int a=(*v.begin()).fr;int b=(*v.begin()).sc;
        cout<<a<<" "<<b<<"\n";
        v.erase(v.begin());
        */
        set<pii>::iterator i=v.begin();
        cout<<(*i).fr<<" "<<(*i).sc<<"\n";
        v.erase(i);
    }
}