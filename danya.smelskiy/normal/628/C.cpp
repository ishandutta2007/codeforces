#include <bits/stdc++.h>
using namespace std;




int n,m;
string s;


int main() {
//    freopen("school.in","r",stdin);
  //  freopen("school.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    cin>>s;
    for (int i=0;i<n && m;++i) {
        int x=s[i]-'a';
        int y='z'-s[i];
        if (x>=y) {
            if (x>=m) x=m;
            while (x>0) {
                --x;
                --m;
                --s[i];
            }
        } else {
            if (y>=m) y=m;
            while (y>0) {
                --y;
                --m;
                ++s[i];
            }
        }
    }
    if (m) {
        cout<<"-1";
        return 0;
    }
    cout<<s;

}