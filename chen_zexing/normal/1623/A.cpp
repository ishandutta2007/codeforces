#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <string.h>
using namespace std;
int main() {
    int T = 1;
    cin >> T;
    while(T--){
        int n,m;
        int x1,y1,x2,y2;
        scanf("%d%d%d%d%d%d",&n,&m,&x1,&y1,&x2,&y2);
        int cnt=0,dx=1,dy=1;
        while(x1!=x2&&y1!=y2){
            //cout<<x1<<" "<<y1<<endl;
            if(x1==n&&dx==1||x1==1&&dx<0) dx=-dx;
            if(y1==1&&dy<1||y1==m&&dy==1) dy=-dy;
            x1+=dx,y1+=dy,cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}