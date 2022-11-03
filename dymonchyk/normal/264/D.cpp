#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <ctime>

using namespace std;

char s[1000006];
char t[1000006];
bool can[101][101]={0};
int nx[1000006][3];
int cnts[1000006][3][3]={0},cntt[1000006][3][3]={0};

int get(char a) {
    return a=='R' ? 0 : a=='B' ? 1 : 2;
}

long long solve() {
    int l1=strlen(s),l2=strlen(t);
    char * ss=s; char * tt=t;
    long long tot=0;
    while(l1&&l2) {
        if (ss[0]==tt[0]) ++tot,--l1,--l2,++ss,++tt;
        else break;
    }
    long long sum=0;
    int up1=l1,up2=l2;
    memset(cnts,0,sizeof(cnts));
    memset(cntt,0,sizeof(cntt));
    for(int it=0;it<2;++it) {
        memset(nx,0,sizeof(nx));
        nx[l2][0]=nx[l2][1]=nx[l2][2]=l2;
        for(int i=l2-1;i>=0;--i) {
            nx[i][0]=nx[i+1][0];
            nx[i][1]=nx[i+1][1];
            nx[i][2]=nx[i+1][2];
            nx[i][get(tt[i])]=i;
        }
        int cpos=0;
        for(int i=0;i<l1&&cpos<l2;++i) {
            int np=nx[cpos][get(ss[i])];
            cpos=np+1;
            if (i==l1-1) l2=min(np+1,l2);
        }
        swap(l1,l2);
        swap(ss,tt);
    }
    ss[l1]=tt[l2]='\0';
    tot+=1LL*l1*l2;
    for(int it=0;it<2;++it) {
        memset(nx,0,sizeof(nx));
        nx[l2][0]=nx[l2][1]=nx[l2][2]=l2;
        for(int i=l2-1;i>=0;--i) {
            nx[i][0]=nx[i+1][0];
            nx[i][1]=nx[i+1][1];
            nx[i][2]=nx[i+1][2];
            nx[i][get(tt[i])]=i;
        }
/*      for(int i=1;i<l1;++i)
            cnts[i][get(ss[i-1])][get(ss[i])]++;
        for(int l=l1-1;l>=0;--l) {
            for(int i=0;i<3;++i)
                for(int j=0;j<3;++j)
                    cnts[l][i][j]+=cnts[l+1][i][j];
        }*/
        for(int i=1;i<l2;++i)
            cntt[i][get(tt[i-1])][get(tt[i])]++;
        for(int l=l2-1;l>=0;--l) {
            for(int i=0;i<3;++i)
                for(int j=0;j<3;++j)
                    cntt[l][i][j]+=cntt[l+1][i][j];
        }
        int cpos=0;
        for(int i=0;i<l1&&cpos<l2;++i) {
            if (i) cnts[0][get(ss[i-1])][get(ss[i])]++;
            int np=nx[cpos][get(ss[i])];
            if (np!=l2) sum+=(l2-1-np);
            cpos=np+1;
            if (np!=l2)
            for(int ii=0;ii<3;++ii)
                for(int jj=0;jj<3;++jj) {
                    if (ii!=jj) sum-=1LL*cnts[0][ii][jj]*cntt[np][jj][ii];
                }
//          if (cpos>=l2) l1=i+1;
            if (i) cnts[0][get(ss[i-1])][get(ss[i])]--;
//          if (it==0&&i==l1-1) up2=np;
//          if (it==1&&i==l1-1) up1=np;
        }
        swap(l1,l2);
        swap(ss,tt);
        memset(cnts,0,sizeof(cnts));
        memset(cntt,0,sizeof(cntt));
    }
    for(int i=1;i<l1;++i)
        cnts[i][get(ss[i-1])][get(ss[i])]++;
    for(int i=1;i<l2;++i)
        cntt[i][get(tt[i-1])][get(tt[i])]++;
    for(int l=l1-1;l>=0;--l) {
        for(int i=0;i<3;++i)
            for(int j=0;j<3;++j)
                cnts[l][i][j]+=cnts[l+1][i][j];
    }
    for(int l=l2-1;l>=0;--l) {
        for(int i=0;i<3;++i)
            for(int j=0;j<3;++j)
                cntt[l][i][j]+=cntt[l+1][i][j];
    }
    for(int i=0;i<3;++i)
        for(int j=0;j<3;++j)
            if (i!=j)
                sum+=1LL*cnts[0][i][j]*cntt[0][j][i];
/*  for(int i=0;i<l1;++i)
        if (tt[0]==ss[i]) {
            sum+=(l1-1-i);
            break;
        }
    for(int i=0;i<l2;++i)
        if (ss[0]==tt[i]) {
            sum+=(l2-1-i);
            break;
        }*/
    return tot-sum;
}

int go(bool out = false) {
    int l1=strlen(s),l2=strlen(t),ans=0;
    memset(can,0,sizeof(can));
    can[0][0]=1;
    for(int i=0;i<l1;++i) {
        for(int j=0;j<l2;++j) {
            if (can[i][j]) {
                ++ans;
                if (s[i]==t[j]) can[i+1][j+1]=1;
                else {
                    can[i+1][j]=can[i][j+1]=1;
                }
            }
            if (out) cout << can[i][j];
        }
        if (out) cout << endl;
    }
    return ans;
}

int main() {
//  freopen("input.txt","r", stdin);
//  freopen("output.txt", "w", stdout);
    gets(s); gets(t);
//  cout << go(true) << endl;
    cout << solve() << endl;
    return 0;
    for(int it=0;it<50;++it) {
        int l1=rand()%10+1,l2=rand()%10+1;
        s[l1]=t[l2]='\0';
        for(int i=0;i<l1;++i) {
            int k=rand()%3;
            s[i]=k==0 ? 'R' : k==1 ? 'G' : 'B';
        }
        for(int i=0;i<l2;++i) {
            int k=rand()%3;
            t[i]=k==0 ? 'R' : k==1 ? 'G' : 'B';
        }
        if (go()!=solve()) {
            cout << "fail\n";
            cout << s << endl << t << endl;
        }
    }
    return 0;
}