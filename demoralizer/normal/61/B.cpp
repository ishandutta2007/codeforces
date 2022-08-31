#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
#define r0 return 0
void cpy(char* b,char* a){
    int l=strlen(b),z=strlen(a);
    int c=0;
    for(int i=0;i<z;i++){
        b[c+l]=a[i];
        c++;
    }
    b[c+l]=0;
}
int iseql(char* a,char* b){
    int l=strlen(a);
    if(l!=strlen(b))r0;
    for(int i=0;i<l;i++)if(a[i]!=b[i])r0;
    return 1;
}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    char s[700],a[3][110],b[6][330];
    for(int j=0;j<3;j++){
        cin>>s;
        int l=strlen(s),c=0;
        for(int i=0;i<l;i++){
            if(s[i]=='-'||s[i]=='_'||s[i]==';')continue;
            if(s[i]>'Z')a[j][c]=s[i];
            else a[j][c]=s[i]+32;
            c++;
        }
        a[j][c]=0;
    }

    int c=0;
    int k[6][3]={{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
    for(int i=0;i<6;i++){
        b[i][0]=0;
        for(int j=0;j<3;j++){
            cpy(b[i],a[k[i][j]]);
        }
    }

    int n;
    cin>>n;
    char d[n][610];
    for(int j=0;j<n;j++){
        cin>>s;
        int l=strlen(s),c=0;
        for(int i=0;i<l;i++){
            if(s[i]=='-'||s[i]=='_'||s[i]==';')continue;
            if(s[i]>'Z')d[j][c]=s[i];
            else d[j][c]=s[i]+32;
            c++;
        }
        d[j][c]=0;
        int r=0;
        for(int q=0;q<6;q++)
            if(iseql(d[j],b[q]))r++;
        if(r==0)cout<<"WA\n";
        else cout<<"ACC\n";
    }
}