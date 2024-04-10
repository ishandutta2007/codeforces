print(
    (lambda go, n, l, r, x, a: 
        go(go, 0, n, l, r, x, a, 0, 10**9, -1)
    )(
        lambda self, i, n, l, r, x, a, s, mi, ma: (
            int(l <= s <= r and ma - mi >= x) if i >= n
            else (
                self(self, i + 1, n, l, r, x, a, s, mi, ma) +
                self(self, i + 1, n, l, r, x, a, s + a[i], min(mi, a[i]), max(ma, a[i]))
            )
        ),
        *map(int, input().split()),
        list(map(int, input().split()))
    )
)