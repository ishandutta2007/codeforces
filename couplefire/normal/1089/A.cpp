#include<bits/stdc++.h>
using namespace std;
int m;
int a,b;
bool dp[201][201][6][6];
pair<int,pair<int,int> > c[201][201][6][6];
int g;
void rec(int a,int b,int mk,int mh)
{
    if(mk==0) return;
    else rec(c[a][b][mk][mh].second.first,c[a][b][mk][mh].second.second,mk-1,c[a][b][mk][mh].first);
    printf("%d:%d ",a-c[a][b][mk][mh].second.first,b-c[a][b][mk][mh].second.second);
}
bool valid(int a,int b,int k,int l) {
    //cout<<a<<" "<<b<<" "<<k<<endl;
    if(!dp[a][b][k][l]) return false;
    if(l>=3 || k-l>=3) return false;
    return true;
}
int main() {
    for(int i=0;i<201;i++) {
        for(int j=0;j<201;j++) {
            for(int k=0;k<6;k++) {
                for(int l=0;l<6;l++) dp[i][j][k][l]=false;
            }
        }
    }
    dp[0][0][0][0]=true;
    for(int i=0;i<201;i++) {
        for(int j=0;j<201;j++) {
            for(int k=1;k<6;k++) {
                for(int h=0;h<6;h++) {
                    g=25;
                    if(k==5) g=15; //Spec case
                    if(i>=g && h>0) { //Pretpostavimo da je prvi tim pobedio
                        for(int l=0;l<=j && l+2<=i;l++) {
                            if(valid(i-max(g,l+2),j-l,k-1,h-1)) {
                                dp[i][j][k][h]=true;
                                c[i][j][k][h]=make_pair(h-1,make_pair(i-max(g,l+2),j-l));
                            }
                        }
                    }
                    if(j>=g) {
                        for(int l=0;l<=i && l+2<=j;l++) {
                            if(valid(i-l,j-max(g,l+2),k-1,h)) {
                                dp[i][j][k][h]=true;
                                c[i][j][k][h]=make_pair(h,make_pair(i-l,j-max(g,l+2)));
                            }
                        }
                    }
                }
            }
        }
    }
    scanf("%d",&m);
    while(m--) {
        scanf("%d %d",&a,&b);
        int mk=-1,mh=-1;
        for(int k=0;k<6;k++) {
            for(int h=0;h<6;h++) {
                if(dp[a][b][k][h] && max(h,k-h)==3 && (mk==-1 || 2*h-k>2*mh-mk)) {
                    mk=k;
                    mh=h;
                }
            }
        }
        if(mk==-1) {
            printf("Impossible\n");
        }
        else {
            printf("%d:%d\n",mh,mk-mh);
            rec(a,b,mk,mh);
            printf("\n");
        }
    }
    return 0;
}