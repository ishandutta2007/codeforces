// Created by calabash_boy on 18-7-3.
#include<bits/stdc++.h>
#define rank rkrk
using namespace std;
typedef long long ll;
const int maxn=2e6+100;
char ch[maxn];
namespace Suffix_Array{
    int cntA[maxn],cntB[maxn],tsa[maxn],A[maxn],B[maxn];
    int sa[maxn],rank[maxn],height[maxn];
    void GetSa(char *ch,int n){
        for(int i=0;i<maxn;i++)  cntA[i]=0;
        for(int i=1;i<=n;i++)   cntA[ch[i]]++;
        for(int i=1;i<=maxn;i++) cntA[i]+=cntA[i-1];
        for(int i=n;i;i--)  sa[cntA[ch[i]]--]=i;
        rank[sa[1]]=1;
        for(int i=2;i<=n;i++){
            rank[sa[i]]=rank[sa[i-1]];
            if(ch[sa[i]]!=ch[sa[i-1]])  rank[sa[i]]++;
        }
        for(int l=1;rank[sa[n]]<n;l<<=1){
            for(int i=0;i<maxn;i++)  cntA[i]=0;
            for(int i=0;i<maxn;i++)  cntB[i]=0;
            for(int i=1;i<=n;i++){
                cntA[A[i]=rank[i]]++;
                cntB[B[i]=(i+l<=n)?rank[i+l]:0]++;
            }
            for(int i=1;i<maxn;i++)   cntB[i]+=cntB[i-1];
            for(int i=n;i;i--)  tsa[cntB[B[i]]--]=i;
            for(int i=1;i<maxn;i++)  cntA[i]+=cntA[i-1];
            for(int i=n;i;i--)  sa[cntA[A[tsa[i]]]--]=tsa[i];
            rank[sa[1]]=1;
            for(int i=2;i<=n;i++){
                rank[sa[i]]=rank[sa[i-1]];
                if(A[sa[i]]!=A[sa[i-1]] || B[sa[i]]!=B[sa[i-1]])    rank[sa[i]]++;
            }
        }
    }
};
int sum[maxn];
struct Segment_Tree{
    int Min[maxn*4];
    void up(int x){
        Min[x] = min(Min[x<<1],Min[x<<1|1]);
    }
    void build(int x,int l,int r){
        if (l == r){
            Min[x] = sum[l];
            return ;
        }
        int mid = l + r >> 1;
        build(x<<1,l,mid);
        build(x<<1|1,mid+1,r);
        up(x);
    }
    int query(int x,int l,int r,int L,int R){
        if (l > R || L > r)return 0x3f3f3f3f;
        if (L <= l && r <= R)return Min[x];
        int mid = l + r >> 1;
        return min(query(x<<1,l,mid,L,R),query(x<<1|1,mid+1,r,L,R));
    }
}seg;
int SUM;
int n,N;
bool check(int x){
    int Min = seg.query(1,1,N,x,x+n-1);
    int begin = sum[x-1];
    if (SUM < 0){
        begin += SUM;
    }
    if (Min >= begin)return 1;
    else return 0;
}
int main(){
    scanf("%s",ch+1);
    n = strlen(ch+1);
    for (int i=n+1;i<=2*n;i++){
        if (ch[i-n] == '(')ch[i-n] = '0';
        else ch[i-n] = '1';
        ch[i] = ch[i-n];
    }
    N = n <<1;
    Suffix_Array::GetSa(ch,N);
    for (int i=1;i<=N;i++){
        sum[i] = sum[i-1];
        if (ch[i] == '0')sum[i] ++;
        else sum[i] --;
    }
    SUM = sum[n];
    seg.build(1,1,N);
    for (int i=1;i<=N;i++){
        int x = Suffix_Array::sa[i];
       // cerr<<ch+x<<endl;
        if (x > n)continue;
        if (check(x)){
            if (SUM < 0){
                for (int j=0;j>SUM;j--){
                    printf("(");
                }
            }
            for (int j=x;j<x+n;j++){
                if (ch[j] == '0')printf("(");
                else printf(")");
            }
            if (SUM > 0){
                for (int j=0;j<SUM;j++){
                    printf(")");
                }
            }
            puts("");
            return 0;
        }
    }
    assert(0);
    return 0;
}