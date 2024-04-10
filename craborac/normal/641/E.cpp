#include <bits/stdc++.h>

using namespace std;

int my_rand()
{
    return (rand() << 16) + rand();
}

struct tree
{
    int x, y;
    int col1, col2;
    tree *l, *r;
    tree(): x(0), y(0), col1(0), col2(0), l(NULL), r(NULL) {}
    tree(int _x)
    {
        x = _x;
        col1 = 0;
        col2 = 0;
        y = my_rand();
        l = NULL;
        r = NULL;
    }
};

int col(tree* v)
{
    if (v == NULL)
        return 0;
    return v->col1 + v->col2 + 1;
}

pair<tree*, tree*> split(tree* v, int x)
{
    if (v == NULL)
        return {v, v};
    if (v->x <= x)
    {
        pair<tree*, tree*> p = split(v->r, x);
        v->r = p.first;
        v->col2 = col(v->r);
        p.first = v;
        return p;
    }
    else
    {
        pair<tree*, tree*> p = split(v->l, x);
        v->l = p.second;
        v->col1 = col(v->l);
        p.second = v;
        return p;
    }
}

tree* merge(tree* v, tree* q)
{
    if (v == NULL)
        return q;
    if (q == NULL)
        return v;
    if (v->y < q->y)
    {
        v->r = merge(v->r, q);
        v->col2 = col(v->r);
        return v;
    }
    else
    {
        q->l = merge(v, q->l);
        v->col1 = col(q->l);
        return q;
    }
}

tree* ins(tree* v, tree* q)
{
    if (v == NULL)
    {
        return q;
    }
    if (q->y < v->y)
    {
        pair<tree*, tree*> p = split(v, q->x);
        q->l = p.first;
        q->col1 = col(q->l);
        q->r = p.second;
        q->col2 = col(q->r);
        return q;
    }
    else if (q->x <= v->x)
    {
        v->l = ins(v->l, q);
        v->col1 = col(v->l);
        return v;
    }
    else
    {
        v->r = ins(v->r, q);
        v->col2 = col(v->r);
        return v;
    }
}

int ans(tree*v, int x)
{
    if (v == NULL)
        return 0;
    if (v->x <= x)
    {
        return ans(v->r, x) + v->col1 + 1;
    }
    else
        return ans(v->l, x);
}

tree* mas1[(int)1e6 + 10];
tree* mas2[(int)1e6 + 10];
int a[(int)1e6 + 10], t[(int)1e6 + 10], x[(int)1e6 + 10], mas[(int)1e6 + 10];

int main()
{
    srand(time(0));
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> t[i] >> x[i];
        mas[i] = x[i];
    }
    sort(mas, mas + n);
    for (int i = 0; i < n; i++)
    {
        //cout << i << endl;
        int l = -1, r = n;
        while (r - l > 1)
        {
            int m = (l + r) / 2;
            if (mas[m] > x[i])
                r = m;
            else
                l = m;
        }
        if (a[i] == 1)
        {
            mas1[l] = ins(mas1[l], new tree(t[i]));
        }
        else if (a[i] == 2)
        {
            mas2[l] = ins(mas2[l], new tree(t[i]));
        }
        else
        {
            cout << ans(mas1[l], t[i]) - ans(mas2[l], t[i]) << endl;
        }
    }
    return 0;
}