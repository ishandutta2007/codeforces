#include <bits/stdc++.h>
using namespace std;



int n;
vector<pair<int,int> > v;


inline bool f(int x,int y,int xx,int yy) {
    if (x>xx || y>yy) return false;
    cout<<"? "<<x<<" "<<y<<" "<<xx<<" "<<yy<<endl;
    string res;
    cin>>res;
    if (res=="YES") return true;
    return false;
}

int main() {
//    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    int x=1;
    int y=1;
    string res1="",res2="";
    while (true) {
        v.push_back(make_pair(x,y));
        if (n-x+n-y<=n-1) break;
        if (f(x,y+1,n,n)) {
            ++y;
            res1+="R";
            continue;
        }
        res1+="D";
        ++x;
    }
    x=n;
    y=n;
    int xx2,yy2;
    while (true) {
        if (x-1+y-1<=n-1) break;
        int xx=x-1;
        int yy=y;
        bool t=false;
        for (int j=v.size()-1;j>=0;--j) {
            xx2=v[j].first;
            yy2=v[j].second;
            if (xx2<=xx && yy2<=yy && xx-xx2+yy-yy2>=n-1) {
                if (f(xx2,yy2,xx,yy)) {
                    t=true;
                    break;
                }
                t=false;
                break;
            }
        }
        if (t) {
            res2+="D";
            --x;
        } else {
            res2+="R";
            --y;
        }
    }
    reverse(res2.begin(),res2.end());
    cout<<"! ";
    res1+=res2;
    cout<<res1<<endl;

}