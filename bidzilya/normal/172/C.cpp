#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

int A[111111];
pair<int,int> K[111111];

int main()
{
        int n,m,g,l,i,j,x;
        __int64 t=0,tt;
        cin >> n >> m;
        for (i=1;i<=n;){
            for (j=0;i<=n && j<m;j++,i++){
                cin >> tt >> x;
                K[j]=make_pair(x,i);
            }
            t = max(t,tt);
            sort(K, K+j);
            for (l=0;l<j;l+=g){
                for (g=0;g+l<j && K[g+l].first==K[l].first;g++)
                    A[K[g+l].second]=t+K[g+l].first;
                t += g/2 +1;
            }
            t += 2*K[j-1].first;
        }

        for (int i=1;i<=n;i++)
            cout << A[i] << ' ';

        return 0;
}