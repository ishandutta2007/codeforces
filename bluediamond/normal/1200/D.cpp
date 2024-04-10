#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=2000+7;
int n,k;
int mt[N][N];
int sum[N][N];
int sum_r[N];
int sum_c[N];

int get(int r1,int c1,int r2,int c2)
{
        return sum[r2][c2]-sum[r2][c1-1]-sum[r1-1][c2]+sum[r1-1][c1-1];
}

int init=0;
int mn[N],mx[N];
int res_c[N];
int add[N];

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
       /// freopen("__input__","r",stdin);

        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
                string s;
                cin>>s;
                int cursum=0;
                for(int j=1;j<=n;j++)
                {
                        if(s[j-1]=='B')
                                mt[i][j]=1;
                        else
                                mt[i][j]=0;
                        sum_r[i]+=mt[i][j];
                        sum_c[j]+=mt[i][j];
                        cursum+=mt[i][j];
                        sum[i][j]=cursum+sum[i-1][j];
                }
        }

        for(int i=1;i<=n;i++)
        {
                for(int j=1;j<=n;j++) if(mt[i][j]) mx[i]=j;
                for(int j=n;j>=1;j--) if(mt[i][j]) mn[i]=j;
        }

        for(int i=1;i<=n;i++) init+=(sum_r[i]==0);
        for(int i=1;i<=n;i++) init+=(sum_c[i]==0);
        int best=0;

        for(int i=1;i+k-1<=n;i++)
        {
                for(int j=1;j<=n;j++)
                {
                        res_c[j]=0;
                        if(sum_c[j] && get(i,j,i+k-1,j)==sum_c[j])
                                res_c[j]=1;
                        res_c[j]+=res_c[j-1];
                }
                for(int j=0;j<=n;j++)
                        add[j]=0;
                for(int r=i;r<=i+k-1;r++)
                {
                        if(sum_r[r])
                        {
                                int l=mn[r];
                                int rr=mx[r];
                                int st=max(0,rr-k+1);
                                int dr=l;
                                if(st>dr)
                                        continue;
                                add[st]++;
                                add[dr+1]--;
                        }
                }
                for(int j=1;j<=n;j++)
                        add[j]+=add[j-1];
                for(int j=1;j+k-1<=n;j++)
                {
                        int now=init+add[j]+res_c[j+k-1]-res_c[j-1];
                        best=max(best,now);
                }
        }
        cout<<best<<"\n";

        return 0;
}
/**


**/