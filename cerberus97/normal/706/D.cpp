#include <iostream>

using namespace std;

struct node
{
    int endingCount;
    node *next[2], *end, **parent;
};

void createNode(node **n)
{
    *n = new node;
    (*n)->next[0] = (*n)->next[1] = (*n)->end = NULL;
    (*n)->parent = NULL;
}

void insert(int x, node **root)
{
    int temp = x, bit = 30, p2 = 1073741824;
    node **cur = root;

    for (; bit >= 0; --bit, p2 /= 2)
    {   
        if (temp >= p2)
        {
            temp -= p2;

            if ((*cur)->next[1] == NULL)
            {
                createNode(&((*cur)->next[1]));
                (*cur)->next[1]->parent = cur;
            }

            cur = &((*cur)->next[1]);
        }

        else
        {
            if ((*cur)->next[0] == NULL)
            {
                createNode(&((*cur)->next[0]));
                (*cur)->next[0]->parent = cur;
            }

            cur = &((*cur)->next[0]);
        }
    }

    if ((*cur)->end == NULL)
    {
        createNode(&((*cur)->end));
        (*cur)->end->parent = cur;
        (*cur)->end->endingCount = 0;
    }

    (*cur)->end->endingCount++;
}

void del(int x, node **cur)
{
    int temp = x, bit = 30, p2 = 1073741824;
    //node **cur = root;

    for (; bit >= 0; --bit, p2 /= 2)
    {   
        if (temp >= p2)
        {
            temp -= p2;
            cur = &((*cur)->next[1]);
        }

        else
        {
            cur = &((*cur)->next[0]);
        }
    }

    cur = &((*cur)->end);

    if ((*cur)->endingCount > 1)
        (*cur)->endingCount--;

    else
    {
        node **temp2;

        while ((*cur)->next[0] == NULL and (*cur)->next[1] == NULL)
        {
            temp2 = (*cur)->parent;
            delete *cur;
            *cur = NULL;
            cur = temp2;
        }
    }
}

int maxXOR(int x, node *root)
{
	int temp = x, bit = 30, p2 = 1073741824, ans = 0;
	node *cur = root;

	for (; bit >= 0; --bit, p2 /= 2)
	{	
		if (temp >= p2)
		{
			temp -= p2;

			if (cur->next[0] != NULL)
			{
				ans += p2;
				cur = cur->next[0];
			}

			else if (cur->next[1] != NULL)
			{
				cur = cur->next[1];
			}

			else
				break;
		}

		else
		{
			if (cur->next[1] != NULL)
			{
				ans += p2;
				cur = cur->next[1];
			}

			else if (cur->next[0] != NULL)
			{
				cur = cur->next[0];
			}

			else
				break;
		}
	}

	return ans;
}

int main()
{
	int q, x;
	char c;
	node *root = new node;
	root->next[0] = root->next[1] = root->end = NULL;
	root->parent = NULL;

	insert(0, &root);

	cin >> q;

	while (q--)
	{
		cin >> c >> x;

		if (c == '+')
			insert(x, &root);

		else if (c == '-')
			del(x, &root);

		else
			cout << maxXOR(x, root) << '\n';
	}
}