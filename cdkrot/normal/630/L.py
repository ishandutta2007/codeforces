#!/usr/bin/python3
# Copyright (C) 2016 Sayutin Dmitry.
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License as
# published by the Free Software Foundation; version 3
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; If not, see <http://www.gnu.org/licenses/>.

def fmt(s, ln):
    while len(s) < ln:
        s = '0' + s
    return s

s = input().strip()

sprime = [None] * 5
sprime[0] = s[0]
sprime[1] = s[2]
sprime[2] = s[4]
sprime[3] = s[3]
sprime[4] = s[1]

num = int("".join(sprime))
print(fmt(str((num ** 5) % (10 ** 5)), 5))