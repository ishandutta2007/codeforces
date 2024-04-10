#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;
#define mt(A,B,C) make_pair(A,make_pair(B,C))
#define mq(A,B,C,D) make_pair(mt(A,B,C),D)
typedef long long ll;
typedef pair<ll,ll>pii;
typedef pair<ll,pii>pi3;
typedef pair<pi3,int>pi4;
ll ret[50000];
ll calc(vector<pi4>inp,int iden)
{
    priority_queue<pi4>que;
    int quesize=inp.size();
    inp.push_back(mq(-1000000000000000000LL,0,0,-1));
    ll now=0;
    ll retu=-1;
    for(int p=0;p<quesize;p++)
    {
        que.push(mq(inp[p].first.second.second,inp[p].first.first,inp[p].first.second.first,inp[p].second));
        pi4 zan=que.top();
        now=max(now,zan.first.second.first);
		for(;;)
		{
			if(que.empty())
			{
				break;
			}
			zan=que.top();
            if(now+zan.first.second.second<=inp[p+1].first.first)
	        {
    		    que.pop();
                now+=zan.first.second.second;
                ret[zan.second]=now;
                if(iden==zan.second)
                {
                    retu=now;
                }
            }
            else
            {
                if(now<inp[p+1].first.first)
                {
                    que.pop();
                    que.push(mq(zan.first.first,zan.first.second.first,zan.first.second.second-(inp[p+1].first.first-now),zan.second));
                    now=inp[p+1].first.first;
                }
				break;
            }
		}
    }
    for(;;)
    {
        if(que.empty())
        {
            break;
        }
        pi4 zan=que.top();
        que.pop();
        now+=zan.first.second.second;
        ret[zan.second]=now;
        if(iden==zan.second)
        {
            retu=now;
        }
    }
    return retu;
}
int main()
{
	FILE *fr=fopen("input.txt","r");
	FILE *fw=fopen("output.txt","w");
    int num;
    fscanf(fr,"%d",&num);
    ll xtim,xsiz,xnum;
    priority_queue<pi4>que;
    map<ll,ll>ma;
    for(int i=0;i<num;i++)
    {
        int za,zb,zc;
        fscanf(fr,"%d%d%d",&za,&zb,&zc);
        if(zc!=-1)
        {
            que.push(mq(-za,zb,zc,i));
            ma[zc]++;
        }
        else
        {
            xtim=za;
            xsiz=zb;
            xnum=i;
        }
    }
    ll ans;
    fscanf(fr,"%I64d",&ans);
    ll beg=1,end=1000000000;
    for(;;)
    {
        ll med=(beg+end)/2;
        vector<pi4>vec;
        priority_queue<pi4>zan=que;
        zan.push(mq(-xtim,xsiz,med,xnum));
        for(;;)
        {
            if(zan.empty())
            {
                break;
            }
            vec.push_back(zan.top());
            vec[vec.size()-1].first.first=-vec[vec.size()-1].first.first;
            zan.pop();
        }
        if(calc(vec,xnum)>ans)
        {
            beg=med+1;
        }
        else
        {
            end=med;
        }
        if(beg==end)
        {
            for(;;)
            {
                if(ma[beg]==0)
                {
                    fprintf(fw,"%I64d\n",beg);
                    priority_queue<pi4>zan=que;
                    zan.push(mq(-xtim,xsiz,beg,xnum));
                    vec.clear();
                    for(;;)
                    {
                        if(zan.empty())
                        {
                            break;
                        }
                        vec.push_back(zan.top());
                        vec[vec.size()-1].first.first=-vec[vec.size()-1].first.first;
                        zan.pop();
                    }
                    calc(vec,xnum);
                    for(int i=0;i<num;i++)
                    {
                        if(i!=0)
                        {
                            fprintf(fw," ");
                        }
                        fprintf(fw,"%I64d",ret[i]);
                    }
                    fprintf(fw,"\n");
                    return 0;
                }
                else
                {
                    beg++;
                }
            }
        }
    }
}