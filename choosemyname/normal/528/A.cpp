#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
typedef pair<long long,int> pii;
int x[200010];
multiset<int> s1,s2,s3,s4;
multiset<int>::iterator it;
char s[5];
int main()
{
    int n,m,k,n1,t1;
    cin>>n>>m>>k;
    s1.insert(0);
    s1.insert(n);
    s2.insert(0);
    s2.insert(m);
    s3.insert(n);
    s4.insert(m);
    for(n1=1;n1<=k;n1++)
    {
        scanf("%s%d",s,&t1);
        if(s[0]=='V')
        {
            it=s1.lower_bound(t1);
            int p=*it;
            it--;
            int q=*it;
            s3.erase(s3.find(p-q));
            s3.insert(p-t1);
            s3.insert(t1-q);
            it=s3.end();
            it--;
            s1.insert(t1);
            long long y=*it;
            it=s4.end();
            it--;
            long long z=*it;
            printf("%I64d\n",y*z);
        }
        else
        {
            it=s2.lower_bound(t1);
            int p=*it;
            it--;
            int q=*it;
            s4.erase(s4.find(p-q));
            s4.insert(p-t1);
            s4.insert(t1-q);
            it=s3.end();
            it--;
            s2.insert(t1);
            long long y=*it;
            it=s4.end();
            it--;
            long long z=*it;
            printf("%I64d\n",y*z);
        }       
    }
}