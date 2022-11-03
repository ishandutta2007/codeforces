#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#define maxint (int)1e9
#define eps 1e-9

string a[1001],b[1001];
int time[1001],n,d,i1[1001],i2[1001];
int cnt =0;
string name[2001];
int used[2001][2001];

int ans =0;
string t1[1001],t2[1001];

int main(){
    cin >> n >> d;
    for (int i=1;i<=n;i++)
        cin >> a[i] >> b[i] >> time[i];
    for (int i=1;i<=n;i++){
        int ind =-1;
        for (int j=1;j<=cnt;j++)
            if (name[j]==a[i]){
                ind = j;
                break;
            }
        if (ind ==-1){
            name[++cnt]=a[i];
            ind = cnt;
        }
        i1[i]=ind;
        ind =-1;
        for (int j=1;j<=cnt;j++)
            if (name[j]==b[i]){
                ind = j;
                break;
            }
        if (ind ==-1){
            name[++cnt]=b[i];
            ind = cnt;
        }
        i2[i]=ind;
    }
    for (int i=1;i<=cnt;i++)
        for (int j=1;j<=cnt;j++)
            used[i][j]=0;

    for (int i=1;i<n;i++)
        for (int j=i+1;j<=n;j++)
            if (i1[i]==i2[j] && i2[i]==i1[j]){
                int t= time[j]-time[i];
                if (t>0 && t<=d && !used[i1[i]][i2[i]]){
                    t1[++ans]=name[i1[i]];
                    t2[ans]=name[i2[i]];
                    used[i1[i]][i2[i]]=1;
                    used[i2[i]][i1[i]]=1;
                }
            }
    cout << ans << endl;
    for (int i=1;i<=ans;i++)
        cout << t1[i] << ' ' << t2[i] << endl;

	return 0;
}