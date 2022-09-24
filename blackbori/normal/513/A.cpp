#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

int n1,n2,k1,k2;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d %d %d %d",&n1,&n2,&k1,&k2);

    if(n1 > n2) printf("First\n");
    else printf("Second");

    return 0;
}