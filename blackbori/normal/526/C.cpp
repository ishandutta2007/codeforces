#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

long long c,hr,hb,wr,wb;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%I64d %I64d %I64d %I64d %I64d",&c,&hr,&hb,&wr,&wb);
    if(hr*wb < hb*wr){
        long long t;
        t=hr; hr=hb; hb=t;
        t=wr; wr=wb; wb=t;
    }

    if(wr > 1000000){
        long long s=0,svalue, m=0;
        while(s*wr<=c){
            svalue = s*hr + (c-s*wr)/wb * hb;
            m = max(m,svalue);
            s++;
        }
        printf("%I64d\n",m);
    }
    else{
        long long s=0,svalue,m=0;
        while(s*wb<=c && s<=wr){
            svalue = s*hb + (c-s*wb)/wr * hr;
            m = max(m,svalue);
            s++;
        }
        printf("%I64d\n",m);
    }

/*
    int s=0, e=c/wr, svalue, evalue, m;
    while(s*wr<=c){
        svalue = s*hr + (c-s*wr)/wb * hb;
        printf("%d\n",svalue);
        s++;
        //evalue = e*hr + (c-e*wr)/wb * hb;
        //m = (s+e)/2;
        //if(svalue < evalue) s=m+1;
        //else e=m;
    }

//    //printf("%d",max(svalue,evalue));
*/
    return 0;
}