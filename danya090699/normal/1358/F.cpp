#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    vector <int> A(n), B(n);
    for(int a=0; a<n; a++) scanf("%lld", &A[a]);
    for(int a=0; a<n; a++) scanf("%lld", &B[a]);
    if(n==1)
    {
        if(A[0]==B[0]) cout<<"SMALL\n0";
        else cout<<"IMPOSSIBLE";
    }
    else if(n==2)
    {
        vector <pair <char, int> > an;
        int su=0;
        while(B[0]!=B[1])
        {
            if(B==A) break;
            if(B[0]>B[1]) an.push_back({'R', 1}), swap(B[0], B[1]);

            int mi=min(A[0], A[1]), ma=max(A[0], A[1]);

            if(B[0]==mi and B[1]>=ma and (B[1]-ma)%B[0]==0)
            {
                int q=(B[1]-ma)/B[0];
                B[1]-=q*B[0];
                an.push_back({'P', q}), su+=q;

                if(A!=B) swap(B[0], B[1]), an.push_back({'R', 1});

                break;
            }

            int q=(B[1]-1)/B[0];
            B[1]-=q*B[0];
            an.push_back({'P', q}), su+=q;
        }
        if(A==B)
        {
            reverse(an.begin(), an.end());
            if(su<=200000)
            {
                int m=0;
                for(int a=0; a<an.size(); a++) m+=an[a].second;
                cout<<"SMALL\n"<<m<<"\n";
                for(int a=0; a<an.size(); a++)
                {
                    while(an[a].second)
                    {
                        cout<<an[a].first;
                        an[a].second--;
                    }
                }
            }
            else cout<<"BIG\n"<<su;
        }
        else cout<<"IMPOSSIBLE";
    }
    else
    {
        string an;
        int su=0;
        while(1)
        {
            if(A==B) break;
            reverse(B.begin(), B.end());
            if(A==B)
            {
                an.push_back('R');
                break;
            }
            reverse(B.begin(), B.end());

            if(B[0]>B[1])
            {
                reverse(B.begin(), B.end());
                an.push_back('R');
            }
            for(int a=n-1; a; a--)
            {
                B[a]-=B[a-1];
                if(B[a]<=0)
                {
                    cout<<"IMPOSSIBLE";
                    return 0;
                }
            }
            an.push_back('P'), su++;
        }
        reverse(an.begin(), an.end());

        if(su<=200000) cout<<"SMALL\n"<<an.size()<<"\n"<<an;
        else cout<<"BIG\n"<<su;
    }
}