#include <bits/stdc++.h>

using namespace std;

const int N=100;

int r=N,c=N;
bool viz[2*N+5][2*N+5];

int dr[]={-1,0,1,0};
int dc[]={0,1,0,-1};

string a;

int f(int i) {
    char ch=a[i];
    if(ch=='U')return 0;
    if(ch=='R')return 1;
    if(ch=='D')return 2;
    if(ch=='L')return 3;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>a;
    int n=a.size();
    viz[N][N]=1;
    for(int i=0;i<n;i++) {
        int rx=r;
        int cx=c;
        r+=dr[f(i)];
        c+=dc[f(i)];
        for(int j=0;j<4;j++) {
            int rn=r+dr[j];
            int cn=c+dc[j];
            if(viz[rn][cn]==1) {
                if(rx==rn && cx==cn)
                    continue;
                cout<<"BUG\n";
                return 0;
            }
        }
        if(viz[r][c]==1) {
            cout<<"BUG\n";
            return 0;
        }
        viz[r][c]=1;
    }
    cout<<"OK\n";
    return 0;
}
/**

**/