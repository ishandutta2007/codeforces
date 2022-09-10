#include <bits/stdc++.h>
#define pii pair<int, int>
#define rep(i,a,b) for(i=a;i<b;++i)
#define repi(i,a,b) for(int i=a;i<b;++i)
#define F first
#define S second
using namespace std;
long long int ans=0;

set<int> cutv;
set<int> cuth;
map<int,int>maxw;
map<int,int>maxh;
int w,h,n;
int main() {
    // your code goes here
    ios::sync_with_stdio(false);
    cutv.insert(0);
    cuth.insert(0);
    cin>>w>>h>>n;
    cutv.insert(w);
    cuth.insert(h);
    
    maxw[w]++;
    maxh[h]++;
    string ty;
    int pos;
    repi(i,0,n)
    {
        cin>>ty;
        cin>>pos;
        if(ty[0]=='V')
        {
            set<int>::iterator up = cutv.lower_bound(pos);
            set<int>::iterator down = up;
            --down;

            auto it = maxw.find((*up - *down));
            (it->second)--;
            if(it->second==0)maxw.erase(it);
            maxw[*up-pos]++;
            maxw[pos-*down]++;
            cutv.insert(pos);
            cout<<(*maxw.rbegin()).first * (long long)(*maxh.rbegin()).first<<endl;
            
        }
        else
        {
            set<int>::iterator up = cuth.lower_bound(pos);
            set<int>::iterator down = up;
            --down;
            
            auto it = maxh.find((*up - *down));
            (it->second)--;
            if(it->second==0)maxh.erase(it);
            maxh[*up-pos]++;
            maxh[pos-*down]++;
            cuth.insert(pos);
            cout<<(*maxh.rbegin()).first * (long long)(*maxw.rbegin()).first <<endl;
        }
    }
    return 0;
}