n = int(input())
l = list(map(int, input().split()))

pref_odd = [0]
curr = 0
for i in range(n):
    if i % 2 == 1:
        curr += l[i]
    pref_odd.append(curr)

pref_even = [0]
curr = 0
for i in range(n):
    if i % 2 == 0:
        curr += l[i]
    pref_even.append(curr)

best = 0
for i in range(n):
    o1 = pref_even[i] + (pref_odd[-1] - pref_odd[i+1])
    o2 = pref_odd[i] + (pref_even[-1] - pref_even[i+1])
    best = max(best,max(o1,o2)+l[i])
print(best)