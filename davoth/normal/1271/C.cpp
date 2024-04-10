#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int N = 2e5 + 10;
int main() {
    fast_io;
    int n,sx,sy,U=0,D=0,L=0,R=0;
    cin >> n >> sx >> sy;
    for(int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        if(x<sx) L++;
        else if(x>sx) R++;
        if(y<sy) D++;
        else if(y>sy) U++;
    }
    if(sx==1e9) R=-1;
    if(sx==0) L=-1;
    if(sy==1e9) U=-1;
    if(sy==0) D=-1;
    if(R>U && R > D && R > L && sx!=1e9){
        cout << R << '\n';
        cout << sx+1 << ' ' << sy;
    }else if(L>U && L>D && sx!=0){
        cout << L << '\n';
        cout << sx-1 << ' ' << sy;
    }else if(U>D){
        cout << U << '\n';
        cout << sx << ' ' << sy+1;
    }else{
        cout << D << '\n';
        cout << sx << ' ' << sy-1;
    }
    return 0;
}