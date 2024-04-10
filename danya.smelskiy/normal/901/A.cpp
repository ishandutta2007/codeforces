#include <bits/stdc++.h>
using namespace std;

int n,pos,all,last;
int a[100005];
int pred1[300005];
int pred2[300005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    ++n;
    pos=0;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        all+=a[i];
        if (i>1 && a[i]>=2 && a[i-1]>=2 && pos==0) {
            pos=i;
            continue;
        }
    }
    if (!pos) {
        cout<<"perfect";
        return 0;
    }
    cout<<"ambiguous"<<'\n';
    last=0;
    for (int i=1;i<=pos-1;++i) {
        int last2=last;
        for (int j=1;j<=a[i];++j) {
            ++last;
            pred1[last]=pred2[last]=last2;
        }
    }
    int last2=last;
    for (int i=pos;i<=n;++i) {
        int last3=last;
        for (int j=1;j<=a[i];++j) {
            ++last;
            pred1[last]=last3;
        }
    }
    last=last2;
    last2=last-1;
    int last3=last;
    for (int i=1;i<=a[pos];++i) {
        ++last;
        if (i==a[pos]) pred2[last]=last3; else
        pred2[last]=last2;
    }



    for (int i=pos+1;i<=n;++i) {
        int last4=last;
        for (int j=1;j<=a[i];++j) {
            ++last;
            pred2[last]=last4;
        }
    }
    for (int i=1;i<=all;++i)
        cout<<pred1[i]<<" ";
    cout<<'\n';
    for (int i=1;i<=all;++i)
        cout<<pred2[i]<<" ";

}