import copy
def get_ints():
    return map(int, raw_input().split(' '))

def change(d, x, dx):
    if not d.has_key(x):
        d[x] = dx
    else:
        d[x] += dx
        
n = int(raw_input())
a = get_ints()
b = get_ints()
c = get_ints()
d = dict()
for i in c:
    change(d, i, 1)
t = copy.copy(d)
for i in b:
    if not t.has_key(i) or t[i] == 0:
        ans1 = i
        change(d, i, 1)
    else:
        change(t, i, -1)
t = copy.copy(d)
for i in a:
    if not t.has_key(i) or t[i] == 0:
        ans2 = i
    else:
        change(t, i, -1)

print ans2
print ans1