def check(w, s):
    j = 0
    for i in range(len(s)):
        while j < len(w) and s[i] != w[j]:
            j += 1
        if j >= len(w) or s[i] != w[j]:
            return False
        j += 1
    return True

n = int(input())
s = input()
t = input()
st = []
i = 0
while i < n and s[i] == t[i]:
    st.append(s[i])
    i += 1
w1 = st[:]
w2 = st[:]
w3 = st[:]
w4 = st[:]
w1.append(s[i])
w1.append(t[i])
w3.append(s[i])
w3.append(t[i])
w2.append(t[i])
w2.append(s[i])
w4.append(t[i])
w4.append(s[i])
for j in range(i + 1, n):
    w1.append(s[j])
    w2.append(t[j])
    w3.append(t[j])
    w4.append(s[j])

res = set()
for ww in (w1, w2, w3, w4):
    www = ''.join(ww)
    if check(www, s) and check(www, t):
        res.add(www)
print(len(res))