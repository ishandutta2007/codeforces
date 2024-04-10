#include <stdio.h>
#include<iostream>
#include<string>
#include <algorithm>
#include <string.h>
#include <vector>
#define LL long long
#define MAX 100005

using namespace std;
long long a[100005];
struct node{
    long long a,b,c;
};
vector <node> v;
int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        scanf("%d",&n);
        long long sum=0;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]),sum+=a[i];
        if(sum%n){
            printf("-1\n");
            continue;
        }
        v.clear();
        for(int i=2;i<=n;i++){
            if(a[i]%i){
                node p;
                p.a=1,p.b=i,p.c=i-a[i]%i;
                v.push_back(p);
                a[1]-=p.c;
                a[i]+=p.c;
            }
            node p;
            p.a=i,p.b=1,p.c=a[i]/i;
            v.push_back(p);
            a[i]=0;
            a[1]+=a[i];
        }
        long long k=sum/n;
        for(int i=2;i<=n;i++){
            node p;
            p.a=1,p.b=i,p.c=k;
            v.push_back(p);
        }
        printf("%d\n",v.size());
        for(int i=0;i<v.size();i++) printf("%lld %lld %lld\n",v[i].a,v[i].b,v[i].c);
    }
    return 0;
}