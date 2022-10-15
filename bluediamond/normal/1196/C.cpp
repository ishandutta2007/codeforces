#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define pb push_back

const int N=(int)1e5+7;
/// 1=x--
/// 2=y++
/// 3=x++
/// 4=y--

int n;
int x[N],y[N];
bool f1[N];
bool f2[N];
bool f3[N];
bool f4[N];
const int inf=(int)1e9;

struct T
{
        int p;
        int dw;
        int up;
};

bool cmp(T a,T b)
{
        return a.p<b.p;
}

vector <T> a;

int gt_cord()
{
        sort(a.begin(),a.end(),cmp);
        int st=-1,dr=n;
        for(int i=0;i<n;i++)
        {
                if(a[i].up)
                        st=i;
                else
                        break;
        }
        for(int i=n-1;i>=0;i--)
        {
                if(a[i].dw)
                        dr=i;
                else
                        break;
        }
        set<int>vls;
        for(int j=st+1;j<=dr-1;j++)
                vls.insert(a[j].p);
        if(vls.size()>=2)
                return inf;
        if(vls.size()==1)
                return *vls.begin();
        if(st!=-1) return a[st].p;
        if(dr!=n) return a[dr].p;
        return inf;
}

int get_x()
{
        a.clear();
        for(int i=1;i<=n;i++)
                a.push_back({x[i],f1[i],f3[i]});
        return gt_cord();
}

int get_y()
{
        a.clear();
        for(int i=1;i<=n;i++)
                a.push_back({y[i],f4[i],f2[i]});
        return gt_cord();
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

       /// cout<<"\n\n\n";

        int q;
        cin>>q;
        while(q--)
        {
                cin>>n;
                for(int i=1;i<=n;i++)
                        cin>>x[i]>>y[i]>>f1[i]>>f2[i]>>f3[i]>>f4[i];
                int a=get_x(),b=get_y();
              ///  cout<<":"<<a<<" "<<b<<"\n";
                if(a==inf || b==inf)
                        cout<<"0\n";
                else
                        cout<<"1 "<<a<<" "<<b<<"\n";
        }

        return 0;
}
/**

**/