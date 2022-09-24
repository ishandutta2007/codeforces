#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>

using namespace std;

string s;
int a[10];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdin);

    int n;
    scanf("%d",&n);
    cin >> s;
    int i;
    for(i=0; i<n; i++){
        switch (s[i]){
        case 'A':
            a[0]++;
            break;
        case 'C':
            a[1]++;
            break;
        case 'G':
            a[2]++;
            break;
        case 'T':
            a[3]++;
            break;
        }
    }

    int m=0,mm=0;

    for(i=0; i<4; i++) if(m < a[i]) m=a[i];
    for(i=0; i<4; i++) if(m == a[i]) mm++;

    long long int ans=1;
    for(i=0; i<n; i++){
        ans *= mm;
        ans %= 1000000007;
    }

    printf("%I64d\n",ans);

    return 0;
}