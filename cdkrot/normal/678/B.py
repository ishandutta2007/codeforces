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

def is_leap(year):
    return (year % 400 == 0 or (year % 100 != 0 and year % 4 == 0))

def main():
    year = int(input())
    newyear = year
    delta = 0
    
    while newyear == year or not (delta == 0 and is_leap(year) == is_leap(newyear)):
        delta += (365 + int(is_leap(newyear)))
        delta %= 7
        newyear += 1
    print(newyear)

main()