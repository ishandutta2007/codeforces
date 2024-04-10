//
// Created by calabash_boy on 18-6-17.
//
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const int maxn = 2000;
bool used[maxn][maxn][4];
int aa,bb,cc,dd,ee,ff,gg,hh;
int a,b,c,d,e,f,g,h;
int A,B,C,D;
bool check1(int x,int y){
    if(y-x==b-a&&x>=c&&x<=a)return 1;
    if(y-x==f-e&&x>=e&&x<=g)return 1;
    if(x+y==a+b&&x>=a&&x<=g)return 1;
    if(x+y==c+d&&x>=c&&x<=e)return 1;
    return 0;
}
bool check2(int x,int y){
    if(y==C||y==D){
        if(x>=A&&x<=B)return 1;
    }
    if(x==A||x==B){
        if(y>=C&&y<=D)return 1;
    }
    return 0;
}
int main(){
#ifndef ONLINE_JUDGE
    // freopen("input.in","r",stdin);
#endif
    cin>>a>>b>>c>>d>>e>>f>>g>>h;
    a+=200;b+=200;
    c+=200;d+=200;
    e+=200;f+=200;
    g+=200;h+=200;
    aa=a;bb=b;cc=c;dd=d;ee=e;ff=f;gg=g;hh=h;
    int iMin = min(min(a,c),min(e,g));
    int iMax = max(max(a,c),max(e,g));
    int jMin = min(min(b,d),min(f,h));
    int jMax = max(max(b,d),max(f,h));
    A = iMin;B = iMax;C = jMin;D = jMax;
    for (int i=iMin+1;i<=iMax;i++){
        for (int j=jMin+1;j<=jMax;j++){
            used[i][j][0]=used[i][j][1]=used[i][j][2]=used[i][j][3]=1;
        }
    }
    cin>>a>>b>>c>>d>>e>>f>>g>>h;
    int delta = b-a;
    if(f-e==delta){
        swap(c,e);
        swap(d,f);
    }else if (h-g==delta){
        swap(c,g);
        swap(d,h);
    }
    if(a<c){
        swap(a,c);
        swap(b,d);
    }
    if(g<e){
        swap(g,e);
        swap(h,f);
    }
    //  cout<<a<<b<<c<<d<<e<<f<<g<<h<<endl;
    if(b-a<f-e){
        swap(a,g);
        swap(b,h);
        swap(c,e);
        swap(d,f);
    }
    a+=200;b+=200;
    c+=200;d+=200;
    e+=200;f+=200;
    g+=200;h+=200;
    for (int i=0;i<1000;i++){
        for (int j=0;j<1000;j++){
            for (int k=0;k<4;k++){
                if(!used[i][j][k])continue;
                if(k==0){
                    int temp = i+j-c-d;
                    if(temp<=1||temp>a+b-c-d+1)continue;
                    if(temp&1){
                        if(j-i>=f-e+1&&j-i<=d-c-1){
                            puts("YES");
                            return 0;
                        }
                    }else{
                        if(j-i>=f-e+2&&j-i<=d-c){
                            puts("YES");
                            return 0;
                        }
                    }
                }else if (k==1){
                    int temp = i+j-c-d;
                    if(temp<=0||temp>a+b-c-d)continue;
                    if(temp&1){
                        if(j-i>=f-e+1&&j-i<=d-c-1){
                            puts("YES");
                            return 0;
                        }
                    }else{
                        if(j-i>=f-e+2&&j-i<=d-c){
                            puts("YES");
                            return 0;
                        }
                    }
                }else if (k==2){
                    int temp = i+j-c-d;
                    if(temp<=0||temp>a+b-c-d)continue;
                    if(temp&1){
                        if(j-i>=f-e+1&&j-i<=d-c-1){
                            puts("YES");
                            return 0;
                        }
                    }else{
                        if(j-i>=f-e&&j-i<=d-c-2){
                            puts("YES");
                            return 0;
                        }
                    }
                }else{
                    int temp = i+j-c-d;
                    if(temp<=1||temp>a+b-c-d+1)continue;
                    if(temp&1){
                        if(j-i>=f-e+1&&j-i<=d-c-1){
                            puts("YES");
                            return 0;
                        }
                    }else{
                        if(j-i>=f-e&&j-i<=d-c-2){
                            puts("YES");
                            return 0;
                        }
                    }
                }
            }
        }
    }
    if(check1(aa,bb)||check1(cc,dd)||check1(ee,ff)||check1(gg,hh)){
        puts("YES");
        return 0;
    }
    if(check2(a,b)||check2(c,d)||check2(e,f)||check2(g,h)){
        puts("YES");
        return 0;
    }
    puts("NO");
    return 0;
}