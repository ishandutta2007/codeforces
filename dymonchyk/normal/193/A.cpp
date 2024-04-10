#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

char arr[52][52]={0};
int dx[]={-1,0,0,1},
    dy[]={0,-1,1,0};


bool check(int n,int m) {
    bool used[52][52]={0};
    vector < pair <int,int> > q;
    for(int i=0;i<n&&q.size()==0;++i)
        for(int j=0;j<m;++j)
            if (arr[i][j]=='#') {
                q.push_back(make_pair(i,j));
                used[i][j]=true;
                break;
            }
    for(int i=0;i<q.size();++i) {
        int x=q[i].first,y=q[i].second;
        for(int t=0;t<4;++t)
            if (x+dx[t]>=0&&x+dx[t]<n&&y+dy[t]>=0&&y+dy[t]<m&&!used[x+dx[t]][y+dy[t]]&&arr[x+dx[t]][y+dy[t]]=='#') {
                used[x+dx[t]][y+dy[t]]=true;
                q.push_back(make_pair(x+dx[t],y+dy[t]));
            }
    }
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if (arr[i][j]=='#'&&!used[i][j]) return false;
    return true;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;++i)
        cin >> arr[i];
    int cnt=0;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            cnt+=arr[i][j]=='#';
    if (cnt<=2) {
        puts("-1");
        return 0;
    }
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if (arr[i][j]=='#') {
                arr[i][j]='.';
                if (!check(n,m)) {
                    puts("1");
                    return 0;
                }
                arr[i][j]='#';
            }
    puts("2");
    return 0;
}