#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        int n=s.size(), us[s.size()], q[26], yk[26], si[26], qq[26][2];
        vector <int> st[26];
        for(int a=0; a<n; a++) us[a]=1;
        for(int i=0; i<26; i++) q[i]=0, yk[i]=0, si[i]=0, qq[i][0]=0, qq[i][1]=0;
        for(int a=0; a+1<s.size(); a++)
        {
            if(s[a]==s[a+1]) q[s[a]-'a']++;
        }
        vector <pair <int, int> > an;
        while(1)
        {
            int ma=0, qnt=0;
            for(int i=0; i<26; i++)
            {
                if(q[i]) qnt++;
                if(q[i]>q[ma]) ma=i;
            }
            if(qnt>1)
            {
                while(qq[ma][0]==0 or qq[ma][1]==0)
                {
                    if(us[yk[ma]])
                    {
                        if(st[ma].size() and us[st[ma].back()] and s[st[ma].back()]==s[yk[ma]])
                        {
                            if(s[yk[ma]]-'a'==ma) qq[ma][0]++;
                            else qq[ma][1]++;
                        }
                        st[ma].push_back(yk[ma]), si[ma]++;
                    }
                    yk[ma]++;
                }

                q[s[st[ma].back()]-'a']--;
                qq[ma][0]--, qq[ma][1]--;
                st[ma].pop_back(), yk[ma]--, si[ma]--;

                int len=0;
                while(1)
                {
                    int p=st[ma].back();
                    st[ma].pop_back();
                    if(us[p])
                    {
                        si[ma]--, len++, us[p]=0, n--;
                        for(int i=0; i<26; i++)
                        {
                            if(st[i].size() and st[i].back()>=p) si[i]--;
                        }

                        if(us[p-1] and s[p]==s[p-1])
                        {
                            for(int i=0; i<26; i++)
                            {
                                if(st[i].size())
                                {
                                    if(st[i].back()>=p)
                                    {
                                        if(i==s[p]-'a') qq[i][0]--;
                                        else qq[i][1]--;
                                    }
                                    if(st[i].back()>=yk[ma])
                                    {
                                        if(i==s[yk[ma]]-'a') qq[i][0]--;
                                        else qq[i][1]--;
                                    }
                                }
                            }

                            q[s[p]-'a']--;
                            break;
                        }
                    }
                }
                an.push_back({si[ma]+1, si[ma]+len});
            }
            else
            {
                if(qnt==1)
                {
                    n-=q[ma];
                    int pref=0;
                    for(int a=0; a+1<s.size(); a++)
                    {
                        if(us[a])
                        {
                            pref++;
                            if(us[a+1] and s[a]==s[a+1] and s[a]-'a'==ma)
                            {
                                an.push_back({pref, pref});
                                pref--;
                            }
                        }
                    }
                }
                break;
            }
        }
        an.push_back({1, n});

        printf("%d\n", an.size());
        for(int a=0; a<an.size(); a++) printf("%d %d\n", an[a].first, an[a].second);
    }
}