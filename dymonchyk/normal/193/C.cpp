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

const int LEN=30000000;
char s1[LEN+1],s2[LEN+1],s3[LEN+1],s4[LEN+1];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int a[5][5]={0},f[5][5];
    for(int i=0;i<3;++i)
        for(int j=i+1;j<=3;++j) {
            cin >> a[i][j];
            a[j][i]=a[i][j];
        }
    for(int i=0;i<4;++i)
        for(int j=0;j<4;++j)
            f[i][j]=a[i][j];
    int l=0,r=10000000;
    int sum=a[0][2]+a[0][3]+a[1][2]+a[1][3];
    while(r-l>1) {
        bool ok=false;
        int len=(r+l)>>1;
        int a2=a[0][1],a1=len-a2,b2=a[2][3],b1=len-b2;
        for(int i=0;i<=a1&&i<=b1;++i) {
            int i1=i,i2=a1-i,i3=b1-i,i4=b2-i2;
            if ((sum-(i2+i3+i4)*2)%4==0&&(sum>=(i2+i3+i4)*2)&&(sum<=(i2+i3+i4)*2+i1*4)) {
                int b13=a[0][2],b14=a[0][3],b23=a[1][2],b24=a[1][3];
                int k1=b13-i2-i4,k2=b14,k3=b23-i2-i3,k4=b24-i3-i4;
                int d=(k1+k2+k3+k4)/4,a=(k2+k4)/2-d,b=(k1+k2)/2-d,c=(k2+k3)/2-d;
                if ((k1+k2+k3+k4)%2==0&&(k2+k4)%2==0&&(k1+k2)%2==0&&(k2+k3)%2==0&&a>=0&&b>=0&&c>=0&&d>=0&&
                    a<=i2&&b<=i3&&c<=i4&&d<=i1) ok=true;
                if (ok) break;
            }
        }
        if (ok) r=len;
        else l=len;
    }
    if (r==10000000) {
        puts("-1");
        return 0;
    }
    int len=r;
    int a2=a[0][1],a1=len-a2,b2=a[2][3],b1=len-b2;
    for(int i=0;i<=a1&&i<=b1;++i) {
        int i1=i,i2=a1-i,i3=b1-i,i4=b2-i2;
        if ((sum-(i2+i3+i4)*2)%4==0&&(sum>=(i2+i3+i4)*2)&&(sum<=(i2+i3+i4)*2+i1*4)) {
            int b13=a[0][2],b14=a[0][3],b23=a[1][2],b24=a[1][3];
            int k1=b13-i2-i4,k2=b14,k3=b23-i2-i3,k4=b24-i3-i4;
            int d=(k1+k2+k3+k4)/4,a=(k2+k4)/2-d,b=(k1+k2)/2-d,c=(k2+k3)/2-d;
            int pos=0;
            for(int i=0;i<d;++i) {
                s1[pos]=s2[pos]='a';
                s3[pos]=s4[pos]='b';
                ++pos;
            }
            for(int i=0;i<i1-d;++i) {
                s1[pos]=s2[pos]='a';
                s3[pos]=s4[pos]='a';
                ++pos;
            }
            for(int i=0;i<a;++i) {
                s1[pos]=s2[pos]='a';
                s3[pos]='a'; s4[pos]='b';
                ++pos;
            }
            for(int i=0;i<i2-a;++i) {
                s1[pos]=s2[pos]='a';
                s3[pos]='b'; s4[pos]='a';
                ++pos;
            }
            for(int i=0;i<b;++i) {
                s3[pos]=s4[pos]='a';
                s1[pos]='b'; s2[pos]='a';
                ++pos;
            }
            for(int i=0;i<i3-b;++i) {
                s3[pos]=s4[pos]='a';
                s1[pos]='a'; s2[pos]='b';
                ++pos;
            }
            for(int i=0;i<c;++i) {
                s3[pos]='a'; s4[pos]='b';
                s1[pos]='a'; s2[pos]='b';
                ++pos;
            }
            for(int i=0;i<i4-c;++i) {
                s3[pos]='a'; s4[pos]='b';
                s1[pos]='b'; s2[pos]='a';
                ++pos;
            }
            break;
        }
    }
    cout << len << endl;
    puts(s1); puts(s2); puts(s3); puts(s4);
    return 0;
}