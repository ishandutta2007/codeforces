#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstring>
#include<cctype>
#define fi first
#define se secode
#define INF 100000000
typedef long long LL;
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    printf("+------------------------+\n");
    char s1[100]={"|#.#.#.#.#.#.#.#.#.#.#.|D|)"};
    char s2[100]={"|#.#.#.#.#.#.#.#.#.#.#.|.|"};
    char s3[100]={"|#.......................|"};
    char s4[100]={"|#.#.#.#.#.#.#.#.#.#.#.|.|)"};
    if(n>=1)
        s1[1]='O';
    for(i=1;i<=10;i++)
    {
        if(n>=i*3+2)
            s1[i*2+1]='O';
    }
    if(n>=2)
        s2[1]='O';
    for(i=1;i<=10;i++)
    {
        if(n>=i*3+3)
            s2[i*2+1]='O';
    }
    if(n>=3) s3[1]='O';
    if(n>=4) s4[1]='O';
    for(i=1;i<=10;i++)
    {
        if(n>=i*3+4)
            s4[i*2+1]='O';
    }
    cout<<s1<<endl<<s2<<endl<<s3<<endl<<s4<<endl;
    printf("+------------------------+\n");
    return 0;
}