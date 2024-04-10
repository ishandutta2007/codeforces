#include<stdio.h>
#include<algorithm>
using namespace std;
struct Line{
    int x[2],y[2];
    void scan(){scanf("%d%d%d%d",&x[0],&y[0],&x[1],&y[1]);}
    bool in(int s,int t){
        if((long long)(x[1]-x[0])*(t-y[0])!=(long long)(s-x[0])*(y[1]-y[0]))return 0;
        if(s!=x[0]){
            if(s>x[0]){
                if((s-x[0])*5<(x[1]-x[0]))return 0;
                if((s-x[0])*5>(x[1]-x[0])*4)return 0;
                return 1;
            }
            else{
                if((x[0]-s)*5<(x[0]-x[1]))return 0;
                if((x[0]-s)*5>(x[0]-x[1])*4)return 0;
                return 1;
            }
        }
        else{
            if(t>y[0]){
                if((t-y[0])*5<(y[1]-y[0]))return 0;
                if((t-y[0])*5>(y[1]-y[0])*4)return 0;
                return 1;
            }
            else{
                if((y[0]-t)*5<(y[0]-y[1]))return 0;
                if((y[0]-t)*5>(y[0]-y[1])*4)return 0;
                return 1;
            }
        }
    }
}a[3];
bool f(Line A,Line B,int x1,int y1,int x2,int y2){
    if(!A.in(x1,y1)||!B.in(x2,y2))return 0;
    return 1;
}
bool Test(Line A,Line B,Line C){
    if(A.x[0]==B.x[1]&&A.y[0]==B.y[1]){
        swap(B.x[1],B.x[0]);
        swap(B.y[1],B.y[0]);
    }
    else if(A.x[1]==B.x[0]&&A.y[1]==B.y[0]){
        swap(A.x[1],A.x[0]);
        swap(A.y[1],A.y[0]);
    }
    else if(A.x[1]==B.x[1]&&A.y[1]==B.y[1]){
        swap(A.x[1],A.x[0]);
        swap(A.y[1],A.y[0]);
        swap(B.x[1],B.x[0]);
        swap(B.y[1],B.y[0]);
    }
    else if(A.x[0]!=B.x[0]||A.y[0]!=B.y[0])return 0;
    if((long long)(A.x[1]-A.x[0])*(B.x[1]-B.x[0])+(long long)(A.y[1]-A.y[0])*(B.y[1]-B.y[0])<0)return 0;
    if(f(A,B,C.x[0],C.y[0],C.x[1],C.y[1])||f(A,B,C.x[1],C.y[1],C.x[0],C.y[0]))return 1;
    return 0;
}
main(){
    int n,i;
    scanf("%d",&n);
    while(n--){
        for(i=0;i<3;i++)a[i].scan();
        if(Test(a[0],a[1],a[2])||Test(a[1],a[2],a[0])||Test(a[2],a[0],a[1]))puts("YES");
        else puts("NO");
    }
}