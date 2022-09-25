#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll

struct point{
    int x,y;
};

point operator -(const point& p1, const point& p2){return {p1.x-p2.x,p1.y-p2.y};}
bool operator <(const point& p1, const point& p2){return p1.x==p2.x?p1.y<p2.y:p1.x<p2.x;}
int operator ^(const point& p1, const point& p2){return p1.x*p2.y-p1.y*p2.x;}//cross

int ori(const point& p1, const point& p2, const point& p3){return (p2-p1)^(p3-p1);}
point bar(const point& p){return {p.x,-p.y};}

set<point> st1,st2;

void Insert(set<point>& st, point p){
    if(st.count(p)) return;
    st.insert(p);
    auto it=st.lower_bound(p);
    if(it!=st.begin()&&next(it)!=st.end()&&ori(*prev(it),p,*next(it))<=0){
        st.erase(p);
        return;
    }
    while(1){
        if(it==st.begin()) break;
        auto it1=prev(it);
        if(it1==st.begin()) break;
        auto it2=prev(it1);
        if(ori(*it2,*it1,p)<=0) st.erase(it1);
        else break;
    }
    while(1){
        if(next(it)==st.end()) break;
        auto it1=next(it);
        if(next(it1)==st.end()) break;
        auto it2=next(it1);
        if(ori(p,*it1,*it2)<=0) st.erase(it1);
        else break;
    }
}

bool solve(set<point>& st, point p){
    if(st.count(p)) return true;
    st.insert(p);
    auto it=st.lower_bound(p);
    if(it!=st.begin()&&next(it)!=st.end()&&ori(*prev(it),p,*next(it))<=0){
        st.erase(p);
        return true;
    }
    st.erase(p);
    return false;
}

int q;

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> q;
    while(q--){
        int op;
        cin >> op;
        if(op==1){
            int x,y;
            cin >> x >> y;
            point p={x,y};
            Insert(st1,p);
            Insert(st2,bar(p));
        }
        else{
            int x,y;
            cin >> x >> y;
            point p={x,y};
            if(solve(st1,p)&&solve(st2,bar(p))) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}