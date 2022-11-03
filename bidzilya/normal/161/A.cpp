#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define maxint (int)1e9
#define eps 1e-9
int a[100001];
vector<pair<int,int> > ans;
int main(){
        int n,k,x,y;
        cin >> n >> k >> x >> y;
        for (int i=1;i<=n;i++)
            cin >> a[i];
        int ya=1;
        for (int yb=1;yb<=k;yb++){
            int b;
            cin >> b;
            while (ya<=n && a[ya]+y<b)ya++;
            if (ya<=n && a[ya]-x<=b && a[ya]+y>=b){
                pair<int,int> temp(ya, yb);
                ans.push_back(temp);
                ya++;
            }
        }
        cout << ans.size() << endl;
        for (int i=0;i<ans.size();i++)
            cout << ans[i].first << ' ' << ans[i].second << endl;
	return 0;
}