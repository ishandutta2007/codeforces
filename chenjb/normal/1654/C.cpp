#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
long long a[210000];
multiset<long long> thomas,waymo;
long long back(multiset<long long> &a)
{
    auto t=a.end(); 
    t--;
    return *t;
}
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        long long n; scanf("%lld",&n);
        long long sum=0;
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++)sum+=a[i];
        thomas.clear();
        waymo.clear();
        thomas.insert(sum);
        for(int i=1;i<=n;i++)waymo.insert(a[i]);
        while (1)
        {
            if (thomas.size()==0)break; //no cake to cut
            //otherwise, taking out the largest
            auto t=back(thomas);
            if (t<back(waymo))break;  //break by not existing
            thomas.erase(thomas.find(t));
            if (waymo.find(t)!=waymo.end())waymo.erase(waymo.find(t));
            else
            {
                thomas.insert(t/2);
                thomas.insert((t+1)/2);
            }
        }
        if (thomas.size()==0)puts("YES"); else puts("NO");
    }
    return 0;
}