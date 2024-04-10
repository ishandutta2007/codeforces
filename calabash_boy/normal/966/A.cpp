#include<bits/stdc++.h>
using namespace std;
int m,n;
set<int>e,l,ee,ll;
int v;
int cl,ce;
int main(){
    scanf("%d%d%d%d%d",&n,&m,&cl,&ce,&v);
    for (int i=0;i<cl;i++){
        int temp;
        scanf("%d",&temp);
        l.insert(temp);
        ll.insert(-temp);
    }
    for (int i=0;i<ce;i++){
        int temp;
        scanf("%d",&temp);
        e.insert(temp);
        ee.insert(-temp);
    }
    int Q;
    scanf("%d",&Q);
    while (Q--){
        int x1,x2,y1,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if (x1==x2){printf("%d\n",abs(y1-y2));continue;}
        swap(x1,y1);
        swap(x2,y2);
        if (e.lower_bound(x1)!=e.lower_bound(x2)){
            //mid e
            printf("%d\n",abs(x1-x2)+(abs(y1-y2)+v-1)/v);
        }else{
            int ans = 0x3f3f3f3f;
            //mid l
            if (l.lower_bound(x1)!=l.lower_bound(x2)){
                ans = min(ans,abs(x1-x2)+abs(y1-y2));
            }
   //         cout<<ans<<endl;
            //left e
            if (x1>x2)swap(x1,x2);
            auto temp = ee.lower_bound(-x1);
            if (temp!=ee.end()){
                int now = *temp;
                ans = min(ans,x1+now+x2+now+(abs(y1-y2)+v-1)/v);
            }
       //     cout<<ans<<endl;
            //right e
            temp = e.lower_bound(x2);
            if (temp!=e.end()){
                int now = *temp;
                ans = min(ans,now-x1+now-x2+(abs(y1-y2)+v-1)/v);
            }
          //  cout<<ans<<endl;
            //left l
            temp = ll.lower_bound(-x1);
            if (temp!=ll.end()){
                int now = *temp;
                ans = min(ans,x1+x2+2*now+abs(y1-y2));
            }
          //  cout<<ans<<endl;
            //right l
            temp= l.lower_bound(x2);
            if (temp!=l.end()){
                int now = *temp;
                ans = min(ans,2*now-x1-x2+abs(y1-y2));
            }
            printf("%d\n",ans);
        }
    }
}