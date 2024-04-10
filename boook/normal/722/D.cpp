#include<bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    while(scanf("%d",&t)==1)
    {
        set<int> s;
        priority_queue<int>pq;
        for(int i=0,q;i<t;i++)
        {
            scanf("%d",&q);
            pq.push(q);
            s.insert(q);
        }

        while(1)
        {
            int q=pq.top();//cout<<q<<"  " ;
            int www=q;
            while(1)
            {
                q/=2;
                if(q==0)break;
                if(!s.count(q))
                {
                    pq.pop();
                    pq.push(q);
                    s.erase(www);
                    s.insert(q);
//                    cout<<q<<endl;
                    break;
                }
            }
            if(q==0)break;
        }
        printf("%d",pq.top());pq.pop();
        while(pq.size())
            printf(" %d",pq.top()),pq.pop();
        puts("");
    }
    return 0;
}