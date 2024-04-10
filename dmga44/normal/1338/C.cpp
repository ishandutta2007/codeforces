#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;

ll ads[4][3];
pip ini_ans[256];

pip solve(ll x)
{
    if(x<256)
        return ini_ans[x];

    int r=x&3;
    pip r1=solve(x/4);
    ll x1=r1.first*4+ads[r][0];
    ll x2=r1.second.first*4+ads[r][1];
    ll x3=r1.second.second*4+ads[r][2];
    return pip(x1,pii(x2,x3));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    set<int> s;
    vector<int> v;
    for(int i=1;i<150;i++)
    {
        if(s.find(i)!=s.end())
            continue;
        for(int j=i+1;1;j++)
        {
            if(s.find(j)!=s.end())
                continue;
            if(s.find(i^j)!=s.end())
                continue;

            s.insert(i);
            s.insert(j);
            s.insert(j^i);
            v.push_back(i);
            v.push_back(j);
            v.push_back(j^i);
            ini_ans[i]=pip(i,pii(j,j^i));
            break;
        }
    }

    ads[1][0]=1;
    ads[1][1]=2;
    ads[1][2]=3;
    ads[2][0]=2;
    ads[2][1]=3;
    ads[2][2]=1;
    ads[3][0]=3;
    ads[3][1]=1;
    ads[3][2]=2;

    int t;
    cin >> t;
    while(t--)
    {
        ll x;
        cin >> x;
        if(x<256)
            db(v[x-1])
        else
        {
            ll v=256;
            while(v<=x)
                v*=4;
            v/=4;

            x-=v;
            int t=x%3;
            ll vv=x/3+v;
            pip res=solve(vv);
            if(t==0)
                db(res.first)
            else if(t==1)
                db(res.second.first)
            else
                db(res.second.second)
        }
    }


    return 0;
}
/**
9
256
257
258
259
260
261
262
263
264

1 2 3
4 8 12
5 10 15
6 11 13
7 9 14
16 32 48
17 34 51
18 35 49
19 33 50
20 40 60
21 42 63
22 43 61
23 41 62
24 44 52
25 46 55
26 47 53
27 45 54
28 36 56
29 38 59
30 39 57
31 37 58
64 128 192
65 130 195
66 131 193
67 129 194
68 136 204
69 138 207
70 139 205
71 137 206
72 140 196
73 142 199
74 143 197
75 141 198
76 132 200
77 134 203
78 135 201
79 133 202
80 160 240
81 162 243
82 163 241
83 161 242
84 168 252
85 170 255
86 171 253
87 169 254
88 172 244
89 174 247
90 175 245
91 173 246
92 164 248
93 166 251
94 167 249
95 165 250
96 176 208
97 178 211
98 179 209
99 177 210
100 184 220
101 186 223
102 187 221
103 185 222
104 188 212
105 190 215
106 191 213
107 189 214
108 180 216
109 182 219
110 183 217
111 181 218
112 144 224
113 146 227
114 147 225
115 145 226
116 152 236
117 154 239
118 155 237
119 153 238
120 156 228
121 158 231
122 159 229
123 157 230
124 148 232
125 150 235
126 151 233
127 149 234
**/